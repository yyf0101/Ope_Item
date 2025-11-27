from enum import Enum
from dataclasses import dataclass, field
from typing import List, Dict, Set

class OpType(Enum):
    SYNC = "Sync"
    COMBINE = "Combine"
    DEMAP = "Demap"
    FFT = "FFT" # Adding FFT for completeness, though maybe not used in the simplified flow

@dataclass
class TaskNode:
    id: int
    name: str
    op_type: OpType
    cycles: int  # Estimated hardware cycles
    parents: List['TaskNode'] = field(default_factory=list)
    children: List['TaskNode'] = field(default_factory=list)

    def add_child(self, child_node):
        self.children.append(child_node)
        child_node.parents.append(self)

    def __repr__(self):
        return f"{self.name}({self.op_type.value}, {self.cycles}cyc)"

def create_mimo_rx_dag(num_antennas=4):
    """
    Creates a DAG for a MIMO Receiver.
    Flow: [Sync x N] -> [Combine] -> [Demap x N]
    """
    tasks = []
    task_id_counter = 0

    # 1. Sync Nodes (One per antenna)
    sync_nodes = []
    for i in range(num_antennas):
        node = TaskNode(
            id=task_id_counter,
            name=f"Sync_Ant{i}",
            op_type=OpType.SYNC,
            cycles=100 # Example: Sync takes 100 cycles
        )
        sync_nodes.append(node)
        tasks.append(node)
        task_id_counter += 1

    # 2. Combine Node (Depends on all Syncs)
    combine_node = TaskNode(
        id=task_id_counter,
        name="MIMO_Combine",
        op_type=OpType.COMBINE,
        cycles=20 # Combine is faster
    )
    task_id_counter += 1
    tasks.append(combine_node)

    for sync_node in sync_nodes:
        sync_node.add_child(combine_node)

    # 3. Demap Nodes (One per antenna, depends on Combine)
    # In reality, Demap might depend on the specific stream, but let's assume
    # the combiner outputs parameters needed for all demaps.
    demap_nodes = []
    for i in range(num_antennas):
        node = TaskNode(
            id=task_id_counter,
            name=f"Demap_Ant{i}",
            op_type=OpType.DEMAP,
            cycles=50 # Demap takes 50 cycles
        )
        demap_nodes.append(node)
        tasks.append(node)
        task_id_counter += 1
    
    for demap_node in demap_nodes:
        combine_node.add_child(demap_node)

    return tasks
