from dataclasses import dataclass
from typing import Dict
from dag_def import OpType

@dataclass
class HardwareSystem:
    """
    Defines the available hardware resources.
    e.g., {OpType.SYNC: 2, OpType.DEMAP: 1} means 2 Sync units and 1 Demap unit.
    """
    resources: Dict[OpType, int]

    @staticmethod
    def default_config():
        # A constrained system:
        # 2 Sync Units (but we have 4 antennas)
        # 1 Combine Unit
        # 2 Demap Units
        return HardwareSystem(resources={
            OpType.SYNC: 2,
            OpType.COMBINE: 1,
            OpType.DEMAP: 2,
            OpType.FFT: 1
        })
