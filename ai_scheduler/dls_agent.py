import copy
from dag_def import OpType

class DLSScheduler:
    """
    Dynamic Level Scheduling (DLS) implementation.
    Reference: G. C. Sih and E. A. Lee, "A Compile-Time Scheduling Heuristic for Interconnection-Constrained Heterogeneous Processor Architectures," IEEE TPDS, 1993.
    """
    def __init__(self, tasks, hardware):
        self.tasks = copy.deepcopy(tasks)
        self.hardware = hardware
        self.task_map = {t.id: t for t in self.tasks}
        self.reconfig_penalty = 20

    def calculate_static_level(self):
        """
        Calculates Static Level (SL) which is equivalent to Upward Rank in HEFT.
        SL(n) = w_n + max(SL(child))
        """
        sl = {}
        
        def get_sl(task):
            if task.id in sl:
                return sl[task.id]
            
            w_n = task.cycles
            if not task.children:
                sl[task.id] = w_n
                return w_n
            
            max_child_sl = 0
            for child in task.children:
                # Find the child object in our local task_map
                child_obj = self.task_map[child.id]
                max_child_sl = max(max_child_sl, get_sl(child_obj))
            
            sl[task.id] = w_n + max_child_sl
            return sl[task.id]

        for task in self.tasks:
            get_sl(task)
        return sl

    def run(self):
        # 1. Initialization
        sl_map = self.calculate_static_level()
        
        # Resource State: [OpType] -> [{'free_time': 0, 'protocol': None}, ...]
        resource_state = {}
        for op_type, count in self.hardware.resources.items():
            resource_state[op_type] = [{'free_time': 0, 'protocol': None, 'id': i} for i in range(count)]

        # Task State
        task_finish_times = {}
        scheduled_tasks = set()
        
        # In-degree calculation
        in_degree = {t.id: 0 for t in self.tasks}
        adj = {t.id: [] for t in self.tasks}
        for t in self.tasks:
            for child in t.children:
                in_degree[child.id] += 1
                adj[t.id].append(child.id)

        # Ready List
        ready_list = [t for t in self.tasks if in_degree[t.id] == 0]
        
        schedule_log = []
        
        total_tasks = len(self.tasks)
        
        while len(scheduled_tasks) < total_tasks:
            if not ready_list:
                # Should not happen in valid DAG unless complete
                break

            best_dl = -float('inf')
            best_pair = None # (task, op_type, unit_idx, start_time, end_time)

            # Evaluate all (Task, Processor) pairs
            for task in ready_list:
                # 1. Data Availability (DA)
                da = 0
                for parent in task.parents:
                    if parent.id in task_finish_times:
                        da = max(da, task_finish_times[parent.id])
                
                # 2. Check available resources
                op_type = task.op_type
                if op_type not in resource_state:
                    continue # Cannot schedule
                
                for unit_idx, unit in enumerate(resource_state[op_type]):
                    tf = unit['free_time']
                    current_proto = unit['protocol']
                    
                    # Calculate Start Time
                    penalty = 0
                    if current_proto is not None and current_proto != task.protocol:
                        penalty = self.reconfig_penalty
                    
                    # Earliest start on this processor
                    start_time = max(da, tf + penalty)
                    
                    # Dynamic Level = Static Level - Start Time
                    # We want to MAXIMIZE this. 
                    # (Prioritize high static level tasks, but penalize if they start late)
                    dl = sl_map[task.id] - start_time
                    
                    if dl > best_dl:
                        best_dl = dl
                        best_pair = (task, op_type, unit_idx, start_time, start_time + task.cycles)

            if not best_pair:
                print("Error: Could not find valid schedule pair.")
                break

            # Commit the best pair
            task, op_type, unit_idx, start, end = best_pair
            
            # Update Resource
            resource_state[op_type][unit_idx]['free_time'] = end
            resource_state[op_type][unit_idx]['protocol'] = task.protocol
            
            # Update Task
            task_finish_times[task.id] = end
            scheduled_tasks.add(task.id)
            ready_list.remove(task)
            
            schedule_log.append({
                'task_id': task.id,
                'name': task.name,
                'start': start,
                'end': end,
                'resource': f"{op_type.value}_{unit_idx}",
                'protocol': task.protocol
            })
            
            # Unlock children
            for child_id in adj[task.id]:
                in_degree[child_id] -= 1
                if in_degree[child_id] == 0:
                    ready_list.append(self.task_map[child_id])

        makespan = 0
        for t in schedule_log:
            makespan = max(makespan, t['end'])
            
        return makespan, schedule_log
