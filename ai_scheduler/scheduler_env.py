import copy
from collections import deque, defaultdict
from dag_def import TaskNode, OpType

class SchedulerEnv:
    def __init__(self, tasks, hardware):
        self.original_tasks = tasks
        self.hardware = hardware

    def simulate(self, priority_list):
        """
        Simulates the execution of tasks based on a priority list.
        priority_list: A list of task IDs. Tasks appearing earlier have higher priority.
        
        Returns:
            makespan: Total cycles to complete all tasks.
            schedule_log: List of (task_name, start_time, end_time, resource_id)
        """
        # 1. Setup
        tasks = copy.deepcopy(self.original_tasks)
        task_map = {t.id: t for t in tasks}
        
        # Calculate in-degrees (dependencies)
        in_degree = {t.id: 0 for t in tasks}
        adj = defaultdict(list)
        for t in tasks:
            for child in t.children:
                # Note: t.children contains copies, but their IDs are consistent
                in_degree[child.id] += 1
                adj[t.id].append(child.id)

        # Priority Map for O(1) lookup
        # Lower index = Higher priority
        prio_map = {tid: i for i, tid in enumerate(priority_list)}

        # Simulation State
        current_time = 0
        completed_tasks = 0
        total_tasks = len(tasks)
        
        # Resources: [OpType] -> [time_when_free_1, time_when_free_2, ...]
        # We track when each unit of a resource type becomes free.
        # NEW: We also track the current protocol state of each resource unit.
        # resource_state[op_type] = [{'free_time': 0, 'protocol': None}, ...]
        resource_state = {}
        for op_type, count in self.hardware.resources.items():
            resource_state[op_type] = [{'free_time': 0, 'protocol': None} for _ in range(count)]

        # Ready Queue (Tasks whose parents are done)
        ready_queue = []
        for t in tasks:
            if in_degree[t.id] == 0:
                ready_queue.append(t)
        
        # Sort ready queue by priority initially
        ready_queue.sort(key=lambda t: prio_map.get(t.id, 9999))

        schedule_log = []
        
        # Reconfiguration Penalty (Cycles)
        RECONFIG_PENALTY = 20

        # We need to know when each task finished.
        task_finish_times = {}

        while completed_tasks < total_tasks:
            if not ready_queue:
                break 

            task = ready_queue.pop(0) # Highest priority
            
            # 1. Dependency Constraint
            parent_finish_time = 0
            for parent in task.parents: 
                pid = parent.id
                if pid in task_finish_times:
                    parent_finish_time = max(parent_finish_time, task_finish_times[pid])
            
            # 2. Resource Constraint
            op_type = task.op_type
            if op_type not in resource_state:
                # Fallback for unknown resources
                units = [{'free_time': 0, 'protocol': None}]
            else:
                units = resource_state[op_type]
            
            best_unit_idx = -1
            best_start_time = float('inf')
            
            # Find the unit that allows the earliest start time, considering reconfig
            for idx, unit in enumerate(units):
                t_free = unit['free_time']
                current_proto = unit['protocol']
                
                # Calculate potential start time
                # If protocol matches or unit is fresh (None), no penalty
                # If protocol differs, add penalty
                penalty = 0
                if current_proto is not None and current_proto != task.protocol:
                    penalty = RECONFIG_PENALTY
                
                # The resource is ready at t_free + penalty
                resource_ready_time = t_free + penalty
                
                # Task can start when resource is ready AND parents are done
                possible_start = max(resource_ready_time, parent_finish_time)
                
                if possible_start < best_start_time:
                    best_start_time = possible_start
                    best_unit_idx = idx
            
            # Schedule it
            start_time = best_start_time
            end_time = start_time + task.cycles
            
            # Update Resource State
            # Note: The unit is technically "busy" reconfiguring during [t_free, t_free+penalty]
            # But for simplicity, we just set the new free time to end_time.
            # The protocol is updated to the new task's protocol.
            resource_state[op_type][best_unit_idx]['free_time'] = end_time
            resource_state[op_type][best_unit_idx]['protocol'] = task.protocol
            
            # Record
            task_finish_times[task.id] = end_time
            schedule_log.append({
                'task_id': task.id,
                'name': task.name,
                'start': start_time,
                'end': end_time,
                'resource': f"{op_type.value}_{best_unit_idx}",
                'protocol': task.protocol
            })
            
            completed_tasks += 1
            
            # Unlock children
            for child_id in adj[task.id]:
                in_degree[child_id] -= 1
                if in_degree[child_id] == 0:
                    child_node = task_map[child_id]
                    ready_queue.append(child_node)
            
            # Re-sort ready queue
            ready_queue.sort(key=lambda t: prio_map.get(t.id, 9999))

        makespan = 0
        for t in schedule_log:
            makespan = max(makespan, t['end'])
            
        return makespan, schedule_log
