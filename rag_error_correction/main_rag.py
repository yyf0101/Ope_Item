import time
import os
from hardware_bridge import HardwareInterface
from rag_core import GraphRAG

def run_complex_scenario(scenario_name, hw, rag, error_type, initial_context, env_snr):
    print(f"\n\n>>> Starting Complex Scenario: {scenario_name} <<<")
    print(f"    Environment SNR: {env_snr} dB")
    
    # Set Environment
    hw.set_env_snr(env_snr)
    
    # 1. Perception (Observe)
    hw.trigger_error(error_type, initial_context)
    
    max_retries = 3
    retry_count = 0
    history = [] # Track history for Agentic RAG
    
    while retry_count < max_retries:
        print(f"\n--- Iteration {retry_count + 1} ---")
        
        # Monitor Loop
        status = hw.get_error_status()
        if status == 0:
            print("[Agent] System Status OK. No action needed.")
            break
            
        # 2. Retrieval (Orient)
        print("[Agent] Error Detected. Starting Retrieval...")
        ctx_data = hw.get_error_context()
        
        # Retrieve from Graph
        graph_context = rag.retrieve_context(status, ctx_data)
        
        # 3. Decision (Decide)
        print("[Agent] Generating Prompt & Querying LLM...")
        error_node_name = error_type # Simplified mapping
        
        # Pass history to prompt generator
        prompt = rag.generate_prompt(error_node_name, graph_context, ctx_data, history=history)
        
        decision = rag.mock_llm_inference(prompt)
        print(f"[Agent] LLM Decision: {decision['reason']}")
        
        # 4. Execution (Act)
        print("[Agent] Validating and Executing Actions...")
        valid_actions = rag.validate_actions(decision)
        
        # Record attempt for history
        attempt_record = {
            "action": str(valid_actions),
            "result": "Pending"
        }
        
        if not valid_actions:
            print("[Agent] No valid actions generated (blocked by filter or empty). Retrying...")
            attempt_record["result"] = "Invalid Action"
            history.append(attempt_record)
            retry_count += 1
            continue

        for action in valid_actions:
            if action["cmd"] == "WRITE":
                # Handle hex string or int
                addr = action["addr"]
                if isinstance(addr, str):
                    addr = int(addr, 0)
                
                # Check if it's a shadow write or trigger
                if addr == 0x50: # Trigger
                    hw.write_csr("UPDATE_TRIGGER", action["val"])
                else:
                    hw.write_shadow_param(addr, action["val"])
            elif action["cmd"] == "RESET":
                print(f"[Agent] Resetting Module: {action['module']}")
        
        # 5. Verification (Wait & Check)
        print("[Agent] Waiting for hardware convergence...")
        time.sleep(0.1) # Wait for physics
        
        # Check if fix worked (Physical Layer Check)
        is_healthy = hw.check_system_health()
        
        if is_healthy:
            hw.write_csr("ERR_STATUS_REG", status) # Clear bits manually if healthy
            print("\n[Agent] SUCCESS: System Recovered and Stable.")
            attempt_record["result"] = "Success"
            history.append(attempt_record)
            break
        else:
            print("\n[Agent] FAILURE: Error persists after fix.")
            attempt_record["result"] = "Failed"
            history.append(attempt_record)
            retry_count += 1
            
    if retry_count == max_retries:
        print("\n[Agent] CRITICAL: Max retries reached. Escalating to human operator.")

def main():
    # Path to the KG JSON generated in Chapter 4
    kg_path = "../knowledge_graph_construction/knowledge_graph.json"
    if not os.path.exists(kg_path):
        print(f"Error: Knowledge Graph file not found at {kg_path}")
        return

    # Initialize System
    hw = HardwareInterface()
    rag = GraphRAG(kg_path)

    # --- Experiment 1: Sync Parameter Mismatch (Ideal Condition) ---
    # Should succeed easily
    context_1 = {"SCS": 15, "Protocol": "5G_NR", "SNR": 20} 
    run_complex_scenario("Sync Parameter Mismatch (Ideal)", hw, rag, "Sync_Loss", context_1, env_snr=20)

    # --- Experiment 2: SNR Sudden Drop (Recoverable) ---
    # Should succeed after adjustment
    context_2 = {"SCS": 30, "Protocol": "5G_NR", "SNR": -2}
    run_complex_scenario("SNR Sudden Drop (Recoverable)", hw, rag, "CRC_Error", context_2, env_snr=-2)

    # --- Experiment 3: Extreme Conditions (Unrecoverable) ---
    # Should fail gracefully without crashing
    context_3 = {"SCS": 30, "Protocol": "5G_NR", "SNR": -12}
    run_complex_scenario("Extreme Deep Fading (Unrecoverable)", hw, rag, "CRC_Error", context_3, env_snr=-12)

if __name__ == "__main__":
    main()
