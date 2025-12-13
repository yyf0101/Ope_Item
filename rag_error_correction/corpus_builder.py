import difflib
import json
import random
import networkx as nx
from networkx.readwrite import json_graph

class CorpusBuilder:
    def __init__(self):
        self.graph = nx.DiGraph()
        self.raw_data = []

    def generate_comprehensive_graph(self):
        """
        Generate a comprehensive Knowledge Graph with 1000+ entries (nodes/edges).
        Focus: Communication Links (LTE, 5G, WiFi) and Hardware (CGRA).
        """
        print("Generating massive Knowledge Graph data (Target: 1000+ entries)...")
        
        # --- 1. Define Entities ---
        protocols = ["LTE", "5G_NR", "WiFi_6", "NB-IoT", "ZigBee"] # Expanded
        
        # Expanded Modules (Hierarchical)
        modules = [
            "Sync_Unit", "Demodulator", "Decoder", "Scheduler", "DMA_Controller", "RF_FrontEnd",
            "FFT_Engine", "Scrambler", "Interleaver", "Rate_Matcher", "CRC_Checker",
            "L1_Controller", "MAC_Filter", "RRC_Manager", "Beam_Forming_Unit"
        ]
        
        # Expanded Conditions
        conditions = [
            "Low_SNR", "High_Doppler", "Interference", "Buffer_Overflow", "Clock_Jitter",
            "Temperature_High", "Voltage_Drop", "Multi_Path_Fading", "Shadowing",
            "Packet_Loss_Burst", "Channel_Congestion", "Neighbor_Cell_Interference"
        ]
        
        # Add base nodes
        for p in protocols: self.graph.add_node(p, label="Protocol")
        for m in modules: self.graph.add_node(m, label="Module")
        for c in conditions: self.graph.add_node(c, label="Condition")

        # --- 2. Generate Registers (Hardware Layer) ---
        # Generate 50 registers
        for i in range(50):
            reg_name = f"REG_0x{1000+i:X}"
            self.graph.add_node(reg_name, label="Register", address=f"0x{1000+i:X}")
            # Link to a random module
            mod = random.choice(modules)
            self.graph.add_edge(reg_name, mod, type="configures")

        # --- 3. Generate Scenarios (Edges) ---
        
        # Scenario A: Synchronization Issues (PHY Layer)
        sync_errors = ["PSS_Miss", "SSS_Detection_Fail", "CFO_Drift", "Timing_Offset", "Frame_Sync_Lost", "Symbol_Boundary_Error"]
        sync_solutions = ["Adjust_Sync_Threshold", "Enable_Freq_Tracking", "Reset_Sync_State", "Switch_Beam", "Widen_Search_Window"]
        
        for proto in protocols:
            for err in sync_errors:
                node_name = f"{proto}_{err}"
                self.graph.add_node(node_name, label="Error", layer="PHY")
                self.graph.add_edge("Sync_Unit", node_name, type="detects")
                self.graph.add_edge(node_name, proto, type="related_to")
                
                # Link to random condition
                cond = random.choice(conditions)
                self.graph.add_edge(cond, node_name, type="causes")
                
                # Link to solution
                sol = f"{proto}_{random.choice(sync_solutions)}_{random.randint(1,100)}" # Unique solution instances
                self.graph.add_node(sol, label="Solution", cost="Low")
                self.graph.add_edge(sol, node_name, type="fixes")

        # Scenario B: Decoding/Demodulation (PHY/MAC)
        demod_errors = ["Constellation_Mismatch", "EVM_High", "LDPC_Decode_Fail", "CRC_Error", "Polar_Code_Fail", "QAM_Demap_Error"]
        demod_solutions = ["Lower_MCS", "Increase_Power", "Request_Retransmission", "Enable_Diversity", "Soft_Reset_Rx"]
        
        for proto in protocols:
            for err in demod_errors:
                node_name = f"{proto}_{err}"
                self.graph.add_node(node_name, label="Error", layer="MAC")
                self.graph.add_edge("Demodulator", node_name, type="detects")
                
                if "EVM" in err:
                    self.graph.add_edge("High_Doppler", node_name, type="causes")
                
                sol = f"{proto}_{random.choice(demod_solutions)}_{random.randint(1,100)}"
                self.graph.add_node(sol, label="Solution", cost="Medium")
                self.graph.add_edge(sol, node_name, type="fixes")

        # Scenario C: System/Hardware (CGRA)
        hw_errors = [
            "Context_Switch_Timeout", "Shadow_Reg_Update_Fail", "DMA_Bus_Hang", "Watchdog_Reset",
            "Instruction_Fetch_Error", "Memory_Parity_Error", "AXI_Bus_Lockup", "FIFO_Underrun"
        ]
        hw_solutions = ["Force_Unlock", "Reset_CGRA_Tile", "Clear_Shadow_Buffer", "Increase_Bus_Priority", "Flush_Pipeline"]
        
        for err in hw_errors:
            self.graph.add_node(err, label="Error", layer="SYS")
            self.graph.add_edge("Scheduler", err, type="monitors")
            
            sol = f"SOL_{random.choice(hw_solutions)}_{random.randint(1,100)}"
            self.graph.add_node(sol, label="Solution", cost="High")
            self.graph.add_edge(sol, err, type="fixes")
            
            # Link to protocols (Mode Switch context)
            self.graph.add_edge("ModeSwitch", err, type="can_trigger")

        # --- 4. Log Entries (Observability Layer) ---
        # Generate 200 Log signatures linked to errors
        for i in range(200):
            log_id = f"LOG_MSG_{i:04d}"
            self.graph.add_node(log_id, label="LogSignature", pattern=f"Error code {i} detected")
            # Link to a random error
            # Get all error nodes
            error_nodes = [n for n, d in self.graph.nodes(data=True) if d.get('label') == 'Error']
            if error_nodes:
                target_err = random.choice(error_nodes)
                self.graph.add_edge(log_id, target_err, type="indicates")

        # --- 5. Expand with Variations to reach ~1000 edges ---
        # Add specific parameter nodes
        params = ["SNR_Threshold", "Retry_Limit", "Beam_Index", "Subcarrier_Spacing", "Coding_Rate", "Modulation_Order"]
        for p in params:
            self.graph.add_node(p, label="Parameter")
            # Link parameters to modules
            self.graph.add_edge(p, random.choice(modules), type="configures")
            
        # Add more random connections to simulate complexity
        existing_nodes = list(self.graph.nodes())
        # Add 300 random edges
        for _ in range(300):
            u = random.choice(existing_nodes)
            v = random.choice(existing_nodes)
            if u != v and not self.graph.has_edge(u, v):
                self.graph.add_edge(u, v, type="correlated_with")

        print(f"Graph Generation Complete.")
        print(f"Nodes: {self.graph.number_of_nodes()}")
        print(f"Edges: {self.graph.number_of_edges()}")

    def save_graph(self, filepath):
        data = json_graph.node_link_data(self.graph)
        with open(filepath, 'w') as f:
            json.dump(data, f, indent=2)
        print(f"Knowledge Graph saved to {filepath}")

if __name__ == "__main__":
    builder = CorpusBuilder()
    builder.generate_comprehensive_graph()
    builder.save_graph("knowledge_db.json")
