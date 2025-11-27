import random
import copy
from scheduler_env import SchedulerEnv

class GeneticScheduler:
    def __init__(self, tasks, hardware, pop_size=50, generations=20, mutation_rate=0.1):
        self.tasks = tasks
        self.hardware = hardware
        self.pop_size = pop_size
        self.generations = generations
        self.mutation_rate = mutation_rate
        self.env = SchedulerEnv(tasks, hardware)
        self.task_ids = [t.id for t in tasks]

    def _initial_population(self):
        """
        Generates random permutations of task IDs.
        Note: A valid topological sort is NOT strictly required for the priority list 
        because the SchedulerEnv respects dependencies regardless of priority.
        However, a topological sort might be a better starting point.
        For simplicity, we use random permutations, as the scheduler handles validity.
        """
        population = []
        for _ in range(self.pop_size):
            ind = copy.copy(self.task_ids)
            random.shuffle(ind)
            population.append(ind)
        return population

    def _fitness(self, individual):
        """
        Lower makespan is better.
        """
        makespan, _ = self.env.simulate(individual)
        return makespan

    def _crossover(self, p1, p2):
        """
        Order Crossover (OX1) for permutation encoding.
        """
        size = len(p1)
        start, end = sorted(random.sample(range(size), 2))
        
        child = [-1] * size
        child[start:end] = p1[start:end]
        
        current_p2_idx = 0
        for i in range(size):
            if child[i] == -1:
                while p2[current_p2_idx] in child:
                    current_p2_idx += 1
                child[i] = p2[current_p2_idx]
        
        return child

    def _mutate(self, individual):
        """
        Swap mutation.
        """
        if random.random() < self.mutation_rate:
            idx1, idx2 = random.sample(range(len(individual)), 2)
            individual[idx1], individual[idx2] = individual[idx2], individual[idx1]
        return individual

    def run(self):
        population = self._initial_population()
        best_schedule = None
        best_makespan = float('inf')
        
        print(f"Starting GA Scheduler (Pop: {self.pop_size}, Gens: {self.generations})")

        for gen in range(self.generations):
            # Evaluate
            fitness_scores = []
            for ind in population:
                score = self._fitness(ind)
                fitness_scores.append((score, ind))
                
                if score < best_makespan:
                    best_makespan = score
                    best_schedule = ind
            
            # Sort by fitness (ascending makespan)
            fitness_scores.sort(key=lambda x: x[0])
            
            # Selection (Top 50%)
            survivors = [ind for score, ind in fitness_scores[:self.pop_size // 2]]
            
            # Next Gen
            new_population = survivors[:]
            while len(new_population) < self.pop_size:
                p1 = random.choice(survivors)
                p2 = random.choice(survivors)
                child = self._crossover(p1, p2)
                child = self._mutate(child)
                new_population.append(child)
            
            population = new_population
            
            if gen % 5 == 0:
                print(f"Gen {gen}: Best Makespan = {best_makespan} cycles")

        print(f"Optimization Complete. Best Makespan: {best_makespan}")
        
        # Get detailed log for best schedule
        _, log = self.env.simulate(best_schedule)
        return best_makespan, log
