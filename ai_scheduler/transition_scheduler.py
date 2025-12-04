import sys
import os
import time
import copy
from dag_def import create_mimo_rx_dag, create_gap_scenario_dag, OpType, TaskNode
from hardware_def import HardwareSystem as Hardware
from ga_agent import GeneticScheduler
from heft_agent import HEFTScheduler
from dls_agent import DLSScheduler
from scheduler_env import SchedulerEnv

def run_transition_optimization():
    print("============================================================")
    print("   Protocol Switching Optimization: LTE -> 5G NR")
    print("   Comparison: Baseline vs. HEFT vs. DLS vs. KG-GA")
    print("============================================================")

    # 1. Define Hardware Resources
    resources = {
        OpType.SYNC: 2,
        OpType.COMBINE: 1,
        OpType.DEMAP: 2,
        OpType.FFT: 1 # Critical Resource for Gap Scenario
    }
    hw = Hardware(resources)
    print(f"[Hardware] Resources: {resources}")

    # 2. Create Tasks (Standard Scenario)
    lte_tasks, next_id = create_mimo_rx_dag(protocol="LTE", num_antennas=4, start_id=0)
    nr_tasks, next_id = create_mimo_rx_dag(protocol="NR", num_antennas=4, start_id=next_id)
    print(f"[Workload] Standard: LTE Tasks: {len(lte_tasks)} | NR Tasks: {len(nr_tasks)}")

    # ---------------------------------------------------------
    # Scenario A-D: Standard Comparison (Already Run)
    # ---------------------------------------------------------
    # ... (Skipping re-run of A-D for brevity, focusing on the new "Trap" scenario)
    # But to keep the script complete, let's keep them or comment them out.
    # Let's just run the new scenario to prove the point.
    
    print("\n============================================================")
    print("   SPECIAL SCENARIO: The 'Greedy Trap'")
    print("   Demonstrating where DLS/HEFT fail and GA succeeds.")
    print("============================================================")
    print("   Setup: 1 FFT Unit. Reconfig Cost = 20.")
    print("   Task 1: Setup_LTE (0-10) -> Sets FFT to LTE.")
    print("   Task 2: Urgent_NR (Ready @ 10) + Heavy Tail (50).")
    print("   Task 3: Future_LTE (Ready @ 15).")
    print("   Greedy Choice (DLS): Pick Urgent_NR due to high Static Level (Tail).")
    print("                        Path: Urgent -> Tail -> Future. Cost: 120.")
    print("   Smart Choice (GA):   Wait for Future_LTE.")
    print("                        Path: Future -> Urgent -> Tail. Cost: 105.")
    
    gap_tasks, _ = create_gap_scenario_dag(start_id=100)
    
    # 1. HEFT
    heft_gap = HEFTScheduler(gap_tasks, hw)
    prio_gap_h = heft_gap.get_priority_list()
    env_gap_h = SchedulerEnv(gap_tasks, hw)
    makespan_h, _ = env_gap_h.simulate(prio_gap_h)
    print(f"\n   [HEFT] Makespan: {makespan_h} cycles")
    
    # 2. DLS
    dls_gap = DLSScheduler(gap_tasks, hw)
    makespan_d, _ = dls_gap.run()
    print(f"   [DLS]  Makespan: {makespan_d} cycles")
    
    # 3. KG-GA
    # We need enough generations to find the "Wait" strategy
    ga_gap = GeneticScheduler(gap_tasks, hw, pop_size=50, generations=30)
    makespan_g, log_g = ga_gap.run()
    print(f"   [KG-GA] Makespan: {makespan_g} cycles")
    
    print("\n   >>> Result Analysis <<<")
    if makespan_g < makespan_d:
        print(f"   SUCCESS: KG-GA beat DLS by {makespan_d - makespan_g} cycles!")
        print("   Reason: GA learned to insert 'Idle Time' to avoid reconfiguration.")
    else:
        print("   Tie/Fail: GA needs tuning.")

if __name__ == "__main__":
    run_transition_optimization()
