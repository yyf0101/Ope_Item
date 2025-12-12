from dag_def import create_mimo_rx_dag
from hardware_def import HardwareSystem
from ga_agent import GeneticScheduler
from heft_agent import HEFTScheduler
from dls_agent import DLSScheduler
from scheduler_env import SchedulerEnv
from utils import print_gantt_chart
import matplotlib.pyplot as plt
import os

def main():
    print("Initializing AI Scheduler for MIMO Receiver...")
    
    # 1. Define Task Graph (4x4 MIMO)
    # Create a mixed workload: LTE + NR + WiFi to test reconfiguration
    tasks_lte, next_id = create_mimo_rx_dag(protocol="LTE", num_antennas=4, start_id=0)
    tasks_nr, next_id = create_mimo_rx_dag(protocol="NR", num_antennas=4, start_id=next_id)
    tasks_wifi, next_id = create_mimo_rx_dag(protocol="WiFi", num_antennas=4, start_id=next_id)
    
    all_tasks = tasks_lte + tasks_nr + tasks_wifi
    print(f"Created Mixed Workload with {len(all_tasks)} nodes.")
    
    # 2. Define Hardware Constraints
    hw = HardwareSystem.default_config()
    print(f"Hardware Resources: {hw.resources}")
    
    results = {}

    # 3. Run HEFT (Baseline 1)
    print("\n--- Running HEFT ---")
    heft = HEFTScheduler(all_tasks, hw)
    heft_prio = heft.get_priority_list()
    env = SchedulerEnv(all_tasks, hw)
    heft_makespan, _ = env.simulate(heft_prio)
    results['HEFT'] = heft_makespan
    print(f"HEFT Makespan: {heft_makespan}")

    # 4. Run DLS (Baseline 2)
    print("\n--- Running DLS ---")
    dls = DLSScheduler(all_tasks, hw)
    dls_makespan, _ = dls.run()
    results['DLS'] = dls_makespan
    print(f"DLS Makespan: {dls_makespan}")

    # 5. Run Standard GA
    print("\n--- Running Standard GA ---")
    ga_std = GeneticScheduler(all_tasks, hw, pop_size=50, generations=30, use_kg_guidance=False)
    ga_std_makespan, _ = ga_std.run()
    results['Standard GA'] = ga_std_makespan
    print(f"Standard GA Makespan: {ga_std_makespan}")

    # 6. Run KG-Guided GA (Proposed)
    print("\n--- Running KG-Guided GA ---")
    ga_kg = GeneticScheduler(all_tasks, hw, pop_size=50, generations=30, use_kg_guidance=True)
    ga_kg_makespan, best_log_kg = ga_kg.run()
    results['KG-Guided GA'] = ga_kg_makespan
    print(f"KG-Guided GA Makespan: {ga_kg_makespan}")
    
    # 7. Visualize Comparison
    print("\n--- Results Summary ---")
    for algo, ms in results.items():
        print(f"{algo}: {ms} cycles")

    # Generate Comparison Plot
    plt.figure(figsize=(10, 6))
    bars = plt.bar(results.keys(), results.values(), color=['gray', 'gray', 'blue', 'green'])
    plt.ylabel('Makespan (Cycles)')
    plt.title('Scheduler Performance Comparison')
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    
    # Add value labels
    for bar in bars:
        height = bar.get_height()
        plt.text(bar.get_x() + bar.get_width()/2., height,
                f'{int(height)}',
                ha='center', va='bottom')

    output_dir = "/home/v-yifengye/Operator_Item/thesis_figures"
    os.makedirs(output_dir, exist_ok=True)
    plt.savefig(os.path.join(output_dir, "scheduler_comparison.png"))
    print(f"Saved comparison plot to {output_dir}/scheduler_comparison.png")

    # Visualize Best Schedule (Gantt)
    # print_gantt_chart(best_log_kg)

if __name__ == "__main__":
    main()
