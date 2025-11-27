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
        resource_state = {}
        for op_type, count in self.hardware.resources.items():
            resource_state[op_type] = [0] * count # All units free at time 0

        # Ready Queue (Tasks whose parents are done)
        ready_queue = []
        for t in tasks:
            if in_degree[t.id] == 0:
                ready_queue.append(t)
        
        # Sort ready queue by priority initially
        ready_queue.sort(key=lambda t: prio_map.get(t.id, 9999))

        schedule_log = []
        
        # Event-based simulation might be faster, but time-stepping is easier to reason about for resource slots
        # Actually, let's use a "next event" approach by tracking resource availability.
        
        # We need to track which tasks are running? No, we can just schedule them.
        # But we have dependencies. A task can only start if:
        # 1. Parents are done (max(parent_end_times))
        # 2. Resource is available
        
        # We need to know when each task finished.
        task_finish_times = {}

        while completed_tasks < total_tasks:
            # If no tasks are ready, we might be in a deadlock (shouldn't happen in DAG)
            # or we are waiting for running tasks to finish.
            
            if not ready_queue:
                # This happens if we are waiting for dependencies.
                # But in this simulation loop, we pop from ready_queue and "schedule" immediately.
                # If ready_queue is empty but completed < total, it means we need to process
                # the completion of tasks to free up dependencies.
                # Wait, the "schedule" logic below determines start/end times immediately.
                # So if ready_queue is empty, it means we processed everything reachable.
                # Ah, we need to update in_degrees as we "schedule" them?
                # Yes.
                break 

            # Pick highest priority task
            # Since we sort by priority, we just iterate and try to schedule
            # But wait, resource availability matters.
            # A high priority task might be blocked by resource, while a lower one is free.
            # "List Scheduling" heuristic: Iterate ready list, schedule first one that has resource?
            # Or strictly follow priority: If top priority is blocked by resource, wait?
            # Standard List Scheduling: Check ready tasks in priority order. 
            # Assign to earliest available resource.
            
            # Let's do this:
            # We maintain the ready_queue sorted by priority.
            # We pop the first task.
            # We find the earliest time it CAN start.
            # Start Time = max(Dependency Ready Time, Resource Ready Time)
            
            # BUT, if we strictly pick the first one, we might delay a later one that could have started earlier on a different resource.
            # However, for a fixed priority list, the standard interpretation is:
            # "Whenever a resource is free, pick the highest priority ready task that can run on it."
            # OR "Iterate tasks, assign to best resource."
            
            # Let's adopt a robust simulation approach:
            # We simulate event by event? No, just calculate start times.
            
            # We need to be careful. If we just calculate start times sequentially based on priority,
            # we are effectively saying "Task A MUST be scheduled before Task B".
            # This is what the GA optimizes: the order in which we consider tasks.
            
            task = ready_queue.pop(0) # Highest priority
            
            # 1. Dependency Constraint
            # When are all parents done?
            parent_finish_time = 0
            for parent in task.parents: # Note: task.parents might be the original objects, need to look up finish times
                # The parent objects in 'task' are from deepcopy, but we need their IDs to look up finish times
                pid = parent.id
                if pid in task_finish_times:
                    parent_finish_time = max(parent_finish_time, task_finish_times[pid])
                else:
                    # Should not happen if logic is correct
                    pass
            
            # 2. Resource Constraint
            # Find the resource unit that becomes free earliest
            op_type = task.op_type
            if op_type not in resource_state:
                # Assume infinite resources if not specified? Or error?
                # Let's assume 1 unit if missing, or error.
                # For safety, assume 1.
                avail_times = [0]
            else:
                avail_times = resource_state[op_type]
            
            # We want the unit that finishes earliest, BUT that time must be >= parent_finish_time?
            # No, the unit becomes free at T_free. The task can start at max(T_free, T_parent).
            # We want to pick the unit that minimizes the start time.
            
            best_unit_idx = -1
            best_start_time = float('inf')
            
            for idx, t_free in enumerate(avail_times):
                possible_start = max(t_free, parent_finish_time)
                if possible_start < best_start_time:
                    best_start_time = possible_start
                    best_unit_idx = idx
            
            # Schedule it
            start_time = best_start_time
            end_time = start_time + task.cycles
            
            # Update Resource State
            resource_state[op_type][best_unit_idx] = end_time
            
            # Record
            task_finish_times[task.id] = end_time
            schedule_log.append({
                'task_id': task.id,
                'name': task.name,
                'start': start_time,
                'end': end_time,
                'resource': f"{op_type.value}_{best_unit_idx}"
            })
            
            completed_tasks += 1
            
            # Unlock children
            for child_id in adj[task.id]:
                in_degree[child_id] -= 1
                if in_degree[child_id] == 0:
                    # Find the child object
                    child_node = task_map[child_id]
                    ready_queue.append(child_node)
            
            # Re-sort ready queue because we added new tasks
            ready_queue.sort(key=lambda t: prio_map.get(t.id, 9999))

        makespan = 0
        for t in schedule_log:
            makespan = max(makespan, t['end'])
            
        return makespan, schedule_log
