from dag_def import TaskNode

class HEFTScheduler:
    def __init__(self, tasks, hardware):
        self.tasks = tasks
        self.hardware = hardware
        # Map ID to task object to ensure we traverse correctly if needed
        self.task_map = {t.id: t for t in tasks}

    def calculate_rank_upward(self):
        """
        Calculates the upward rank for each task.
        Rank_u(n_i) = w_i + max_{n_j in succ(n_i)} (Rank_u(n_j))
        """
        ranks = {}
        
        # We need to traverse from exit nodes up to entry nodes (reverse topological)
        # Or just use recursion with memoization.
        
        def get_rank(task):
            if task.id in ranks:
                return ranks[task.id]
            
            # Execution cost (w_i)
            w_i = task.cycles
            
            if not task.children:
                ranks[task.id] = w_i
                return w_i
            
            max_child_rank = 0
            for child in task.children:
                # Ensure we are looking at the task object that corresponds to the child
                # In our DAG generation, references are preserved, so 'child' is the object.
                max_child_rank = max(max_child_rank, get_rank(child))
            
            ranks[task.id] = w_i + max_child_rank
            return ranks[task.id]

        for task in self.tasks:
            get_rank(task)
            
        return ranks

    def get_priority_list(self):
        """
        Returns a list of task IDs sorted by Rank_u descending.
        """
        ranks = self.calculate_rank_upward()
        # Sort tasks by rank descending
        # Tie-breaking: Random or ID? Let's use ID for stability.
        sorted_tasks = sorted(self.tasks, key=lambda t: (ranks[t.id], -t.id), reverse=True)
        return [t.id for t in sorted_tasks]
