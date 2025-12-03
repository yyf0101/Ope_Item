import os
import sys
import subprocess
import time
import re

# Add subdirectories to path
sys.path.append(os.path.join(os.path.dirname(__file__), "knowledge_graph_construction"))
sys.path.append(os.path.join(os.path.dirname(__file__), "rag_error_correction"))

# Import modules
# Note: We might need to handle imports inside the modules if they use relative imports
# But based on file content, they seem to use absolute or local imports that might work if CWD is right.
# To be safe, we will run them as subprocesses or ensure CWD is handled.

from rag_core import GraphRAG

def run_command(command, cwd=None):
    print(f"[Workflow] Running: {command} in {cwd}")
    result = subprocess.run(command, shell=True, cwd=cwd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"[Workflow] Error: {result.stderr}")
    return result.stdout

def write_sim_config(path, config):
    with open(path, "w") as f:
        for k, v in config.items():
            f.write(f"{k}={v}\n")
    print(f"[Workflow] Wrote config to {path}: {config}")

def parse_sim_log(log_path):
    errors = []
    if not os.path.exists(log_path):
        print(f"[Workflow] Log file not found: {log_path}")
        return errors
    
    with open(log_path, "r") as f:
        for line in f:
            if "[Error]" in line:
                errors.append(line.strip())
    return errors

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    kg_dir = os.path.join(base_dir, "knowledge_graph_construction")
    sim_dir = os.path.join(base_dir, "multi_standard_rx_project", "sim")
    rag_dir = os.path.join(base_dir, "rag_error_correction")
    
    kg_json_path = os.path.join(kg_dir, "knowledge_graph.json")
    sim_config_path = os.path.join(sim_dir, "sim_config.txt")
    sim_log_path = os.path.join(sim_dir, "sim.log")

    print("==================================================")
    print("   SDR + Knowledge Graph + RAG Auto-Correction    ")
    print("==================================================")

    # ---------------------------------------------------------
    # Step 1: Build Knowledge Graph
    # ---------------------------------------------------------
    print("\n>>> Step 1: Constructing Knowledge Graph...")
    # We run it as a subprocess to avoid import issues with relative paths in the script
    run_command(f"{sys.executable} main_kg.py", cwd=kg_dir)
    
    if not os.path.exists(kg_json_path):
        print("Error: Knowledge Graph not generated.")
        return

    # ---------------------------------------------------------
    # Step 2: Initial Simulation (With Error)
    # ---------------------------------------------------------
    print("\n>>> Step 2: Running Simulation with INCORRECT Parameters...")
    # Scenario: We set SCS=15, but NR requires 30. This should trigger Sync Loss.
    initial_config = {
        "NR_SWITCH_TIME": 2000,
        "WIFI_SWITCH_TIME": 10000,
        "SCS": 15,   # Wrong! Should be 30 for NR
        "SNR": 20
    }
    write_sim_config(sim_config_path, initial_config)
    
    # Rebuild simulation to ensure C++ changes are picked up
    print("[Workflow] Recompiling simulation...")
    run_command("make clean sim", cwd=sim_dir)
    
    print("[Workflow] Running simulation...")
    run_command("make run_log", cwd=sim_dir)
    
    # ---------------------------------------------------------
    # Step 3: Error Detection
    # ---------------------------------------------------------
    print("\n>>> Step 3: Analyzing Logs...")
    errors = parse_sim_log(sim_log_path)
    if not errors:
        print("[Workflow] No errors detected. (Unexpected for this demo)")
        return
    
    print(f"[Workflow] Detected {len(errors)} errors:")
    for e in errors:
        print(f"  {e}")
        
    # Take the first error
    first_error = errors[0]
    # Parse error type and context (Mock parsing)
    error_type = "Unknown"
    if "Sync_Loss" in first_error:
        error_type = "Sync_Loss"
    elif "CRC_Error" in first_error:
        error_type = "CRC_Error"
        
    print(f"[Workflow] Diagnosing Error: {error_type}")

    # ---------------------------------------------------------
    # Step 4: RAG Diagnosis & Correction
    # ---------------------------------------------------------
    print("\n>>> Step 4: RAG Agent Activation...")
    rag = GraphRAG(kg_json_path)
    
    # Mock Context based on config
    runtime_context = {"SCS": initial_config["SCS"], "SNR": initial_config["SNR"], "Protocol": "5G_NR"}
    
    # Retrieve
    context_info = rag.retrieve_context(1 if error_type == "Sync_Loss" else 2, runtime_context)
    
    # Generate Prompt
    prompt = rag.generate_prompt(error_type, context_info, runtime_context, error_desc=first_error)
    # print(f"[Debug] Prompt:\n{prompt}")
    
    # Inference
    decision = rag.mock_llm_inference(prompt)
    print(f"[Agent] Diagnosis: {decision['reason']}")
    
    # Validate
    actions = rag.validate_actions(decision)
    print(f"[Agent] Proposed Actions: {actions}")
    
    if not actions:
        print("[Workflow] No valid actions suggested. Aborting.")
        return

    # ---------------------------------------------------------
    # Step 5: Apply Fix & Re-run
    # ---------------------------------------------------------
    print("\n>>> Step 5: Applying Fix and Re-running...")
    
    new_config = initial_config.copy()
    
    for action in actions:
        if action["cmd"] == "WRITE":
            addr = action["addr"]
            val = action["val"]
            # Map address to config key (Mock mapping)
            # In rag_core.py: 0x14 is SCS, 0x10 is SYNC_THRESH
            if addr == "0x14" or addr == 0x14:
                print(f"[Workflow] Applying Fix: Setting SCS to {val}")
                new_config["SCS"] = val
            elif addr == "0x10" or addr == 0x10:
                print(f"[Workflow] Applying Fix: Setting SYNC_THRESH to {val}")
                # We don't have SYNC_THRESH in config yet, but let's add it
                new_config["SYNC_THRESH"] = val
            elif addr == "0x18" or addr == 0x18:
                 print(f"[Workflow] Applying Fix: Setting AGC_GAIN to {val}")
                 # new_config["AGC_GAIN"] = val
            
    write_sim_config(sim_config_path, new_config)
    
    print("[Workflow] Running simulation with CORRECTED parameters...")
    run_command("make run_log", cwd=sim_dir)
    
    # ---------------------------------------------------------
    # Step 6: Final Verification
    # ---------------------------------------------------------
    print("\n>>> Step 6: Final Verification...")
    final_errors = parse_sim_log(sim_log_path)
    
    if not final_errors:
        print("[Workflow] SUCCESS! No errors detected in the corrected run.")
        print("[Workflow] System recovered automatically.")
    else:
        print(f"[Workflow] FAILURE. Errors persist: {final_errors}")

if __name__ == "__main__":
    main()
