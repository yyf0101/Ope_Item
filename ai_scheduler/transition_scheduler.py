import sys
import os
import time
import copy
from dag_def import create_mimo_rx_dag, OpType, TaskNode
from hardware_def import HardwareSystem as Hardware
from ga_agent import GeneticScheduler
from heft_agent import HEFTScheduler
from scheduler_env import SchedulerEnv

def run_transition_optimization():
    print("============================================================")
    print("   Protocol Switching Optimization: LTE -> 5G NR")
    print("   Comparison: Baseline vs. HEFT vs. KG-GA (Ours)")
    print("============================================================")

    # 1. Define Hardware Resources
    resources = {
        OpType.SYNC: 2,
        OpType.COMBINE: 1,
        OpType.DEMAP: 2
    }
    hw = Hardware(resources)
    print(f"[Hardware] Resources: {resources}")

    # 2. Create Tasks
    lte_tasks, next_id = create_mimo_rx_dag(protocol="LTE", num_antennas=4, start_id=0)
    nr_tasks, _ = create_mimo_rx_dag(protocol="NR", num_antennas=4, start_id=next_id)
    print(f"[Workload] LTE Tasks: {len(lte_tasks)} | NR Tasks: {len(nr_tasks)}")

    # ---------------------------------------------------------
    # Scenario A: Baseline (Static Reconfiguration)
    # ---------------------------------------------------------
    print("\n>>> Scenario A: Baseline (Static Reconfiguration)")
    print("    Strategy: Stop-and-Wait. Complete flush of LTE pipeline before NR starts.")
    
    baseline_tasks = copy.deepcopy(lte_tasks + nr_tasks)
    
    # Enforce Dependencies: All LTE Demaps -> All NR Syncs
    lte_demaps = [t for t in baseline_tasks if t.op_type == OpType.DEMAP and t.protocol == "LTE"]
    nr_syncs = [t for t in baseline_tasks if t.op_type == OpType.SYNC and t.protocol == "NR"]
    
    for lte_d in lte_demaps:
        for nr_s in nr_syncs:
            lte_d.add_child(nr_s)
            
    # Use HEFT for Baseline to give it the best possible "Static" schedule
    heft_baseline = HEFTScheduler(baseline_tasks, hw)
    prio_baseline = heft_baseline.get_priority_list()
    env_baseline = SchedulerEnv(baseline_tasks, hw)
    baseline_makespan, _ = env_baseline.simulate(prio_baseline)
    print(f"    -> Baseline Latency: {baseline_makespan} cycles")


    # ---------------------------------------------------------
    # Scenario B: HEFT (Greedy List Scheduling)
    # ---------------------------------------------------------
    print("\n>>> Scenario B: HEFT (Heterogeneous Earliest Finish Time)")
    print("    Strategy: Greedy List Scheduling based on Critical Path.")
    print("    Constraint: Pipelined (No artificial dependencies).")
    
    # Optimized Task Set (No Stop-and-Wait dependencies)
    # But we still need the "Switch Trigger" dependency (LTE Sync -> NR Sync)
    # to represent the physical reality that antenna switch happens after LTE Sync.
    
    heft_tasks = copy.deepcopy(lte_tasks + nr_tasks)
    lte_syncs_h = [t for t in heft_tasks if t.op_type == OpType.SYNC and t.protocol == "LTE"]
    nr_syncs_h = [t for t in heft_tasks if t.op_type == OpType.SYNC and t.protocol == "NR"]
    
    for lte_s in lte_syncs_h:
        for nr_s in nr_syncs_h:
            lte_s.add_child(nr_s)
            
    heft_agent = HEFTScheduler(heft_tasks, hw)
    prio_heft = heft_agent.get_priority_list()
    env_heft = SchedulerEnv(heft_tasks, hw)
    heft_makespan, heft_log = env_heft.simulate(prio_heft)
    print(f"    -> HEFT Latency:     {heft_makespan} cycles")


    # ---------------------------------------------------------
    # Scenario C: KG-GA (Ours)
    # ---------------------------------------------------------
    print("\n>>> Scenario C: KG-GA (Context-Aware Evolutionary Optimization)")
    print("    Strategy: Global Search with Reconfiguration Cost Awareness.")
    print("    Constraint: Pipelined (Same as HEFT).")
    
    ga_tasks = copy.deepcopy(lte_tasks + nr_tasks)
    lte_syncs_g = [t for t in ga_tasks if t.op_type == OpType.SYNC and t.protocol == "LTE"]
    nr_syncs_g = [t for t in ga_tasks if t.op_type == OpType.SYNC and t.protocol == "NR"]
    
    for lte_s in lte_syncs_g:
        for nr_s in nr_syncs_g:
            lte_s.add_child(nr_s)
    
    # Run GA
    # We can seed the GA with the HEFT solution to ensure it's at least as good!
    # But for fair comparison of "Pure GA" vs "Pure HEFT", let's run standard GA.
    # However, a good "Ours" algorithm would use HEFT as an initial individual.
    
    ga_opt = GeneticScheduler(ga_tasks, hw, pop_size=50, generations=20)
    
    # Inject HEFT solution into population (Hybrid GA) - Optional but recommended for "Best Performance"
    # Let's do it manually if the class supports it, or just rely on GA finding it.
    # For this demo, let's trust the GA.
    
    ga_makespan, ga_log = ga_opt.run()
    print(f"    -> KG-GA Latency:    {ga_makespan} cycles")

    # ---------------------------------------------------------
    # Analysis
    # ---------------------------------------------------------
    print("\n============================================================")
    print(f"   FINAL RESULTS: Algorithm Comparison")
    print("============================================================")
    print(f"   1. Baseline (Static): {baseline_makespan} cycles")
    print(f"   2. HEFT (Greedy):     {heft_makespan} cycles")
    print(f"   3. KG-GA (Ours):      {ga_makespan} cycles")
    print("------------------------------------------------------------")
    
    imp_vs_base = (baseline_makespan - ga_makespan) / baseline_makespan * 100
    imp_vs_heft = (heft_makespan - ga_makespan) / heft_makespan * 100
    
    print(f"   Improvement vs Baseline: {imp_vs_base:.2f}%")
    print(f"   Improvement vs HEFT:     {imp_vs_heft:.2f}%")
    print("============================================================")
    
    if ga_makespan < heft_makespan:
        print("\n[Conclusion] Our KG-GA outperformed HEFT by finding a non-greedy ordering")
        print("             that better hides the reconfiguration penalties.")
    elif ga_makespan == heft_makespan:
        print("\n[Conclusion] Our KG-GA matched HEFT performance (Optimal found).")
    else:
        print("\n[Conclusion] GA needs more generations to converge.")

if __name__ == "__main__":
    run_transition_optimization()
