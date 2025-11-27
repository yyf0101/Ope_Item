from dag_def import create_mimo_rx_dag
from hardware_def import HardwareSystem
from ga_agent import GeneticScheduler
from utils import print_gantt_chart

def main():
    print("Initializing AI Scheduler for MIMO Receiver...")
    
    # 1. Define Task Graph (4x4 MIMO)
    tasks = create_mimo_rx_dag(num_antennas=4)
    print(f"Created Task Graph with {len(tasks)} nodes.")
    
    # 2. Define Hardware Constraints
    # Let's try a constrained scenario to make scheduling interesting
    # 2 Sync Units, 1 Combine Unit, 2 Demap Units
    hw = HardwareSystem.default_config()
    print(f"Hardware Resources: {hw.resources}")
    
    # 3. Run AI Scheduler (Genetic Algorithm)
    agent = GeneticScheduler(tasks, hw, pop_size=50, generations=30)
    best_makespan, best_schedule_log = agent.run()
    
    # 4. Visualize
    print_gantt_chart(best_schedule_log)

if __name__ == "__main__":
    main()
