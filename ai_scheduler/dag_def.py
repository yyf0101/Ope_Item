from enum import Enum
from dataclasses import dataclass, field
from typing import List, Dict, Set, Optional

class OpType(Enum):
    SYNC = "Sync"
    COMBINE = "Combine"
    DEMAP = "Demap"
    FFT = "FFT"
    RECONFIG = "Reconfig" # Virtual Op for reconfiguration

@dataclass
class TaskNode:
    id: int
    name: str
    op_type: OpType
    cycles: int
    protocol: str = "Common" # "LTE", "NR", "WiFi"
    parents: List['TaskNode'] = field(default_factory=list)
    children: List['TaskNode'] = field(default_factory=list)

    def add_child(self, child_node):
        self.children.append(child_node)
        child_node.parents.append(self)

    def __repr__(self):
        return f"{self.name}({self.op_type.value}, {self.protocol}, {self.cycles}cyc)"

def create_mimo_rx_dag(protocol="LTE", num_antennas=4, start_id=0):
    """
    Creates a DAG for a MIMO Receiver.
    Flow: [Sync x N] -> [Combine] -> [Demap x N]
    Returns: (tasks, next_start_id)
    """
    tasks = []
    task_id_counter = start_id

    # Protocol specific parameters
    sync_cycles = 100 if protocol == "LTE" else 120 # NR might be more complex
    demap_cycles = 50 if protocol == "LTE" else 80

    # 1. Sync Nodes (One per antenna)
    sync_nodes = []
    for i in range(num_antennas):
        node = TaskNode(
            id=task_id_counter,
            name=f"{protocol}_Sync_Ant{i}",
            op_type=OpType.SYNC,
            cycles=sync_cycles,
            protocol=protocol
        )
        sync_nodes.append(node)
        tasks.append(node)
        task_id_counter += 1

    # 2. Combine Node (Depends on all Syncs)
    combine_node = TaskNode(
        id=task_id_counter,
        name=f"{protocol}_MIMO_Combine",
        op_type=OpType.COMBINE,
        cycles=20,
        protocol=protocol
    )
    task_id_counter += 1
    tasks.append(combine_node)

    for sync_node in sync_nodes:
        sync_node.add_child(combine_node)

    # 3. Demap Nodes (One per antenna, depends on Combine)
    demap_nodes = []
    for i in range(num_antennas):
        node = TaskNode(
            id=task_id_counter,
            name=f"{protocol}_Demap_Ant{i}",
            op_type=OpType.DEMAP,
            cycles=demap_cycles,
            protocol=protocol
        )
        demap_nodes.append(node)
        tasks.append(node)
        task_id_counter += 1
    
    for demap_node in demap_nodes:
        combine_node.add_child(demap_node)

    return tasks, task_id_counter

def create_gap_scenario_dag(start_id=0):
    """
    Creates a specific scenario to trick greedy algorithms (DLS/HEFT).
    Scenario:
    - Resource is in LTE mode.
    - An NR task is ready immediately.
    - An LTE task becomes ready slightly later.
    - Greedy algo will switch to NR immediately (incurring penalty).
    - Optimal algo will wait for LTE task (avoiding penalty), then switch.
    """
    tasks = []
    curr_id = start_id
    
    # 1. Setup Task (Sets resource to LTE)
    setup_lte = TaskNode(id=curr_id, name="Setup_LTE", op_type=OpType.FFT, cycles=10, protocol="LTE")
    tasks.append(setup_lte)
    curr_id += 1
    
    # 2. Timer Task (Delays the Future LTE task)
    # Runs on a different resource (SYNC) so it doesn't block FFT
    timer = TaskNode(id=curr_id, name="Timer_Delay", op_type=OpType.SYNC, cycles=15, protocol="Common")
    tasks.append(timer)
    curr_id += 1
    
    # 3. Urgent NR Task (Ready after Setup)
    urgent_nr = TaskNode(id=curr_id, name="Urgent_NR", op_type=OpType.FFT, cycles=10, protocol="NR")
    setup_lte.add_child(urgent_nr)
    tasks.append(urgent_nr)
    curr_id += 1
    
    # 3b. Urgent Tail (Increases Static Level of Urgent Path)
    # This tricks DLS into thinking Urgent path is critical, ignoring the switch cost
    urgent_tail = TaskNode(id=curr_id, name="Urgent_Tail", op_type=OpType.FFT, cycles=50, protocol="NR")
    urgent_nr.add_child(urgent_tail)
    tasks.append(urgent_tail)
    curr_id += 1
    
    # 4. Future LTE Task (Ready after Timer)
    future_lte = TaskNode(id=curr_id, name="Future_LTE", op_type=OpType.FFT, cycles=10, protocol="LTE")
    timer.add_child(future_lte)
    # Also depends on Setup to ensure logical consistency, though Timer is the bottleneck
    setup_lte.add_child(future_lte) 
    tasks.append(future_lte)
    curr_id += 1
    
    return tasks, curr_id

