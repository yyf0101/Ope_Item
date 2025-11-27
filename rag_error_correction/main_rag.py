from rag_core import VectorDatabase
from hardware_bridge import HardwareInterface
import time

def main():
    print("============================================================")
    print("   RAG-Based Automatic Error Correction System (Demo)       ")
    print("============================================================")

    # 1. Initialize Components
    db = VectorDatabase("/home/v-yifengye/rag_error_correction/knowledge_db.json")
    hw = HardwareInterface()

    # 2. Simulation Loop
    # Scenario: The system is running, and suddenly a Sync Error occurs.
    
    print("\n--- Simulation Start ---")
    
    # Step A: Inject Error
    hw.inject_error("sync_fail")
    
    # Step B: Monitor detects error
    current_status = hw.read_status()
    if "ERROR" in current_status:
        print(f"\n[Monitor] Detected Issue: {current_status}")
        
        # Step C: RAG Retrieval
        print("[RAG] Querying Knowledge Base for solution...")
        results = db.search(current_status, top_k=1)
        
        if results:
            score, doc = results[0]
            print(f"[RAG] Found Solution (Confidence: {score:.2f})")
            print(f"  -> Reference: {doc['3gpp_ref']}")
            print(f"  -> Suggested Fix: {doc['solution_text']}")
            print(f"  -> Action Code: {doc['action_code']}")
            
            # Step D: Apply Fix
            print("[Controller] Executing automated fix...")
            hw.apply_fix(doc['action_code'])
            
        else:
            print("[RAG] No solution found.")
    
    print("\n--- Simulation Scenario 2 ---")
    
    # Step A: Inject another error
    hw.inject_error("demod_fail")
    
    # Step B: Monitor
    current_status = hw.read_status()
    if "ERROR" in current_status:
        print(f"\n[Monitor] Detected Issue: {current_status}")
        
        # Step C: RAG
        print("[RAG] Querying Knowledge Base...")
        results = db.search(current_status, top_k=1)
        
        if results:
            score, doc = results[0]
            hw.apply_fix(doc['action_code'])

    print("\n============================================================")
    print("   System Status: " + hw.read_status())
    print("============================================================")

if __name__ == "__main__":
    main()
