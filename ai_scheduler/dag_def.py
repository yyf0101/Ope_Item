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

