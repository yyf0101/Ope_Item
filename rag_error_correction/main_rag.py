import time
import os
from hardware_bridge import HardwareInterface
from rag_core import GraphRAG

def run_scenario(scenario_name, hw, rag, error_type, context):
    print(f"\n\n>>> Starting Scenario: {scenario_name} <<<")
    
    # 1. Perception (Observe)
    hw.trigger_error(error_type, context)
    
    # Monitor Loop
    status = hw.get_error_status()
    if status != 0:
        # 2. Retrieval (Orient)
        print("\n[Agent] Error Detected. Starting Retrieval...")
        ctx_data = hw.get_error_context()
        
        # Retrieve from Graph
        graph_context = rag.retrieve_context(status, ctx_data)
        
        # 3. Decision (Decide)
        print("\n[Agent] Generating Prompt & Querying LLM...")
        error_node_name = error_type # Simplified mapping
        prompt = rag.generate_prompt(error_node_name, graph_context, ctx_data)
        
        # print(f"--- Prompt Preview ---\n{prompt[:200]}...\n--------------------")
        
        decision = rag.mock_llm_inference(prompt)
        print(f"[Agent] LLM Decision: {decision['reason']}")
        
        # 4. Execution (Act)
        print("\n[Agent] Validating and Executing Actions...")
        valid_actions = rag.validate_actions(decision)
        
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
        
        # Verify Fix
        # In simulation, we assume if actions were taken, error clears
        if len(valid_actions) > 0:
            hw.write_csr("ERR_STATUS_REG", status) # Clear bits
            print("\n[Agent] Fix Applied. Error Status Cleared.")
        else:
            print("\n[Agent] No valid actions to apply.")

def main():
    # Path to the KG JSON generated in Chapter 4
    kg_path = "../knowledge_graph_construction/knowledge_graph.json"
    if not os.path.exists(kg_path):
        print(f"Error: Knowledge Graph file not found at {kg_path}")
        return

    # Initialize System
    hw = HardwareInterface()
    rag = GraphRAG(kg_path)

    # --- Experiment 1: Sync Parameter Mismatch ---
    # Context: SCS configured to 15kHz, but should be 30kHz for 5G NR
    context_1 = {"SCS": 15, "Protocol": "5G_NR", "SNR": 20} 
    run_scenario("Sync Parameter Mismatch", hw, rag, "Sync_Loss", context_1)

    # --- Experiment 2: SNR Sudden Drop ---
    # Context: SNR drops to -5dB, causing CRC errors
    context_2 = {"SCS": 30, "Protocol": "5G_NR", "SNR": -5}
    run_scenario("SNR Sudden Drop", hw, rag, "CRC_Error", context_2)

if __name__ == "__main__":
    main()
