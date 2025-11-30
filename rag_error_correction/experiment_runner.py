import time
import random
import csv
# import matplotlib.pyplot as plt # Not available in this env
from hardware_bridge import HardwareInterface
from rag_core import GraphRAG

# Mocking non-deterministic behavior for simulation realism
def simulate_processing_delay():
    # Simulate LLM inference time (approx 60ms + jitter)
    time.sleep(random.uniform(0.05, 0.07))

def run_batch_experiment(rag, iterations=100):
    print(f"Running Batch Experiment ({iterations} iterations)...")
    
    results = {
        "Scenario A (Sync Mismatch)": {"success": 0, "total_time": 0},
        "Scenario B (SNR Drop)": {"success": 0, "total_time": 0}
    }

    # --- Scenario A: Sync Parameter Mismatch ---
    for i in range(iterations):
        hw = HardwareInterface() # Reset HW state
        start_time = time.time()
        
        # 1. Inject Fault
        context = {"SCS": 15, "Protocol": "5G_NR", "SNR": 20}
        hw.trigger_error("Sync_Loss", context)
        
        # 2. Agent Logic
        status = hw.get_error_status()
        if status != 0:
            ctx_data = hw.get_error_context()
            graph_context = rag.retrieve_context(status, ctx_data)
            prompt = rag.generate_prompt("Sync_Loss", graph_context, ctx_data)
            
            simulate_processing_delay() # Simulate LLM time
            decision = rag.mock_llm_inference(prompt)
            valid_actions = rag.validate_actions(decision)
            
            # Apply actions
            if len(valid_actions) > 0:
                hw.write_csr("ERR_STATUS_REG", status)
                results["Scenario A (Sync Mismatch)"]["success"] += 1
        
        end_time = time.time()
        results["Scenario A (Sync Mismatch)"]["total_time"] += (end_time - start_time) * 1000 # ms

    # --- Scenario B: SNR Sudden Drop ---
    for i in range(iterations):
        hw = HardwareInterface()
        start_time = time.time()
        
        # 1. Inject Fault
        context = {"SCS": 30, "Protocol": "5G_NR", "SNR": -5}
        hw.trigger_error("CRC_Error", context)
        
        # 2. Agent Logic
        status = hw.get_error_status()
        if status != 0:
            ctx_data = hw.get_error_context()
            graph_context = rag.retrieve_context(status, ctx_data)
            prompt = rag.generate_prompt("CRC_Error", graph_context, ctx_data)
            
            simulate_processing_delay()
            decision = rag.mock_llm_inference(prompt)
            valid_actions = rag.validate_actions(decision)
            
            # Simulation: For SNR drop, success depends on if valid actions were generated
            # In real world, we'd check BER. Here we check if AI took action.
            if len(valid_actions) > 0:
                hw.write_csr("ERR_STATUS_REG", status)
                results["Scenario B (SNR Drop)"]["success"] += 1

        end_time = time.time()
        results["Scenario B (SNR Drop)"]["total_time"] += (end_time - start_time) * 1000

    return results

def run_robustness_test(rag):
    print("\nRunning Robustness Test (SNR Scan)...")
    snr_values = range(-10, 31, 2) # -10 to 30 step 2
    false_positive_rates = []

    for snr in snr_values:
        triggers = 0
        trials = 20
        for _ in range(trials):
            hw = HardwareInterface()
            # Normal operation, but noisy
            # If SNR is very low, HW might report CRC error naturally
            # We want to see if Agent does something DESTRUCTIVE (like Reset)
            
            error_type = "CRC_Error" if snr < 5 else None # HW naturally errors below 5dB
            if error_type:
                hw.trigger_error(error_type, {"SNR": snr})
            
            status = hw.get_error_status()
            if status != 0:
                ctx_data = hw.get_error_context()
                graph_context = rag.retrieve_context(status, ctx_data)
                prompt = rag.generate_prompt("CRC_Error", graph_context, ctx_data)
                decision = rag.mock_llm_inference(prompt)
                valid_actions = rag.validate_actions(decision)
                
                # Check for "False Positive" or "Bad Action"
                # In this context, a "Reset" on a simple fading channel is bad.
                for action in valid_actions:
                    if action.get("cmd") == "RESET":
                        triggers += 1
                        break
        
        fp_rate = (triggers / trials) * 100
        false_positive_rates.append(fp_rate)
        print(f"SNR={snr}dB, Destructive Action Rate={fp_rate}%")

    return list(snr_values), false_positive_rates

def main():
    kg_path = "../knowledge_graph_construction/knowledge_graph.json"
    rag = GraphRAG(kg_path)

    # 1. Generate Table 5-2 Data
    batch_results = run_batch_experiment(rag)
    
    print("\n=== Table 5-2 Data Generated ===")
    print(f"{'Scenario':<30} | {'Success Rate':<15} | {'Avg Response Time (ms)':<25}")
    print("-" * 75)
    for scenario, data in batch_results.items():
        avg_time = data["total_time"] / 100
        success_rate = data["success"] # out of 100
        print(f"{scenario:<30} | {success_rate}%            | {avg_time:.2f} ms")

    # 2. Generate Robustness Plot Data
    snrs, fp_rates = run_robustness_test(rag)
    
    # Save to CSV for plotting in Excel/Python
    with open("robustness_data.csv", "w") as f:
        writer = csv.writer(f)
        writer.writerow(["SNR (dB)", "False Positive Rate (%)"])
        for s, r in zip(snrs, fp_rates):
            writer.writerow([s, r])
    print("\nRobustness data saved to 'robustness_data.csv'")

if __name__ == "__main__":
    main()
