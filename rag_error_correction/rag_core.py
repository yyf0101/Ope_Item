import json
import math
import networkx as nx
from networkx.readwrite import json_graph

class GraphRAG:
    """
    Implements the GraphRAG logic: Retrieval, Prompt Engineering, and Decision Making.
    """
    def __init__(self, graph_path):
        self.graph = self._load_graph(graph_path)
        print(f"GraphRAG Initialized. Loaded {len(self.graph.nodes)} nodes.")

    def _load_graph(self, path):
        with open(path, 'r') as f:
            data = json.load(f)
        # Handle both node-link formats if necessary, assuming standard format here
        return json_graph.node_link_graph(data)

    def retrieve_context(self, error_code, context_data):
        """
        5.3.1 Hybrid Retrieval Strategy (Simplified for Demo)
        """
        print(f"[RAG] Retrieving context for ErrorCode: {error_code}...")
        
        # 1. Identify Error Node
        error_node = None
        # Simple mapping from bitmask to ID
        if error_code & 1:
            error_node = "Sync_Loss"
        elif error_code & 2:
            error_node = "CRC_Error"
            
        if not error_node or error_node not in self.graph:
            print(f"[RAG] Warning: Error node '{error_node}' not found in graph.")
            return []

        # 2. Graph Traversal (K-Hop)
        # Find causes (upstream) and configures (downstream)
        subgraph_nodes = {error_node}
        
        # Reverse 'causes' to find what module caused it
        # In our graph: Module -[causes]-> Error. So we look for predecessors.
        potential_causes = list(self.graph.predecessors(error_node))
        subgraph_nodes.update(potential_causes)
        
        for module in potential_causes:
            # Find registers that configure this module
            # Register -[configures]-> Module. Predecessors of Module.
            regs = list(self.graph.predecessors(module))
            subgraph_nodes.update(regs)
            
            # Find protocols implemented by this module
            # Module -[implements]-> Protocol. Successors of Module.
            protos = list(self.graph.successors(module))
            subgraph_nodes.update(protos)

        # Extract subgraph info
        context_info = []
        for node in subgraph_nodes:
            node_data = self.graph.nodes[node]
            # Add edges
            edges = self.graph.out_edges(node, data=True)
            edge_info = [f"- {node} {d.get('type', 'related_to')} {target}" for _, target, d in edges if target in subgraph_nodes]
            
            context_info.append({
                "id": node,
                "type": node_data.get("label", "Unknown"),
                "props": node_data,
                "relations": edge_info
            })
            
        return context_info

    def generate_prompt(self, error_node, context_info, runtime_context):
        """
        5.3.2 Structured Prompt Engineering
        """
        # Serialize Graph Context
        graph_text = ""
        for item in context_info:
            props_str = ", ".join([f"{k}={v}" for k, v in item['props'].items() if k != 'label'])
            graph_text += f"Node: {item['id']} ({item['type']}) [{props_str}]\n"
            for rel in item['relations']:
                graph_text += f"  {rel}\n"

        prompt = f"""
[Role] You are an expert in FPGA-based communication systems.
[Task] Analyze the following hardware error and generate a fix action.

[Context from Knowledge Graph]
{graph_text}

[Runtime State]
Error: {error_node}
Context: {runtime_context}

[Reasoning Chain]
1. Identify the error and the module reporting it.
2. Check the runtime context (SNR, SCS, etc.) against the module's configuration and protocol standards.
3. Use the graph to find the register controlling the relevant parameter.
4. Formulate a fix action.

[Output Format]
JSON: {{"reason": "...", "actions": [{{"cmd": "WRITE", "addr": "0x...", "val": "..."}}, {{"cmd": "RESET", "module": "..."}}]}}
"""
        return prompt

    def mock_llm_inference(self, prompt):
        """
        Simulates the LLM decision (5.2.1 Decision Phase).
        In a real system, this calls Llama-3 or GPT-4.
        Here we use heuristics based on the prompt content to simulate intelligence.
        """
        print("[AI] LLM Thinking...")
        
        # Heuristic 1: Sync Loss + High Threshold/Low SNR -> Lower Threshold
        if "Sync_Loss" in prompt and "SNR" in prompt:
            # Parse SNR from prompt (simulated)
            # Assuming prompt contains "SNR=..."
            return {
                "reason": "Sync Loss detected. Runtime context shows low SNR. Graph indicates SYNC_THRESH controls sensitivity. Lowering threshold to improve detection probability.",
                "actions": [
                    {"cmd": "WRITE", "addr": "0x10", "val": 0.3}, # 0x10 is SYNC_THRESH address (mock)
                    {"cmd": "WRITE", "addr": "0x50", "val": 0xA5A5} # Trigger Update
                ]
            }
        
        # Heuristic 2: Sync Loss + SCS Mismatch -> Fix SCS
        if "Sync_Loss" in prompt and "SCS" in prompt:
            # If context says SCS=15 but Protocol says 30 (implied logic)
            return {
                "reason": "Sync Loss detected. Runtime SCS is 15kHz, but 5G NR FR1 standard (from Graph) requires 30kHz. Correcting SCS configuration.",
                "actions": [
                    {"cmd": "WRITE", "addr": "0x14", "val": 30}, # 0x14 is SCS address (mock)
                    {"cmd": "WRITE", "addr": "0x50", "val": 0xA5A5}
                ]
            }

        # Heuristic 3: CRC Error + Low SNR -> Adjust AGC
        if "CRC_Error" in prompt and "SNR" in prompt:
             return {
                "reason": "CRC Error detected. Low SNR indicates signal fading. Increasing AGC gain to compensate.",
                "actions": [
                    {"cmd": "WRITE", "addr": "0x18", "val": 30}, # 0x18 is AGC Gain (mock)
                    {"cmd": "WRITE", "addr": "0x50", "val": 0xA5A5}
                ]
            }

        return {"reason": "Unknown error pattern.", "actions": []}

    def validate_actions(self, decision):
        """
        5.3.3 Rule-based Filter
        """
        print("[Filter] Validating AI actions...")
        valid_actions = []
        
        # Mock Register Map for Validation
        valid_addresses = [0x10, 0x14, 0x18, 0x50]
        
        for action in decision.get("actions", []):
            if action["cmd"] == "WRITE":
                addr = int(str(action["addr"]), 0) # Handle hex string
                if addr not in valid_addresses:
                    print(f"  [BLOCK] Illegal Address: {hex(addr)}")
                    continue
                # Value check (simple)
                if addr == 0x10 and (action["val"] > 1.0 or action["val"] < 0):
                     print(f"  [BLOCK] Invalid Threshold Value: {action['val']}")
                     continue
                     
            valid_actions.append(action)
            
        return valid_actions
