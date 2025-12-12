import random
import copy
from scheduler_env import SchedulerEnv

class GeneticScheduler:
    def __init__(self, tasks, hardware, pop_size=50, generations=20, mutation_rate=0.1, use_kg_guidance=False):
        self.tasks = tasks
        self.hardware = hardware
        self.pop_size = pop_size
        self.generations = generations
        self.mutation_rate = mutation_rate
        self.use_kg_guidance = use_kg_guidance
        self.env = SchedulerEnv(tasks, hardware)
        self.task_ids = [t.id for t in tasks]

    def _get_topological_sort(self, protocol_bias=False):
        """
        Generates a topological sort of the DAG.
        If protocol_bias is True, it tries to group tasks of the same protocol
        to minimize reconfiguration penalties (simulating KG knowledge).
        """
        # Build graph
        in_degree = {t.id: 0 for t in self.tasks}
        adj = {t.id: [] for t in self.tasks}
        task_map = {t.id: t for t in self.tasks}
        
        for t in self.tasks:
            for child in t.children:
                in_degree[child.id] += 1
                adj[t.id].append(child.id)
        
        # Ready queue
        ready = [t.id for t in self.tasks if in_degree[t.id] == 0]
        topo_order = []
        
        last_protocol = None
        
        while ready:
            # Selection heuristic
            if protocol_bias and last_protocol:
                # Try to find a task with the same protocol
                candidates = [tid for tid in ready if task_map[tid].protocol == last_protocol]
                if candidates:
                    next_tid = random.choice(candidates)
                else:
                    next_tid = random.choice(ready)
            else:
                next_tid = random.choice(ready)
            
            ready.remove(next_tid)
            topo_order.append(next_tid)
            last_protocol = task_map[next_tid].protocol
            
            for neighbor in adj[next_tid]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    ready.append(neighbor)
                    
        # If cycle exists or disconnected (shouldn't happen for DAG), fill rest
        if len(topo_order) < len(self.tasks):
            remaining = list(set(self.task_ids) - set(topo_order))
            random.shuffle(remaining)
            topo_order.extend(remaining)
            
        return topo_order

    def _initial_population(self):
        """
        Generates initial population.
        If use_kg_guidance is True, uses topological sort and protocol clustering.
        """
        population = []
        for _ in range(self.pop_size):
            if self.use_kg_guidance:
                # Mix of pure topological and protocol-biased topological
                if random.random() < 0.7:
                    ind = self._get_topological_sort(protocol_bias=True)
                else:
                    ind = self._get_topological_sort(protocol_bias=False)
            else:
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
        history = []
        
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
            
            # Record history
            history.append(best_makespan)

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
        return best_makespan, log, history
