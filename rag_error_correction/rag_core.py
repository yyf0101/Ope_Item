import json
import math
import random
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
        print(f"Loading graph from: {path}")
        with open(path, 'r') as f:
            data = json.load(f)
        print(f"Data type: {type(data)}")
        # Handle both node-link formats if necessary, assuming standard format here
        return json_graph.node_link_graph(data)

    # --- New: Pipeline Classification ---
    def pipeline_classification(self, error_code):
        """
        Optimization: Classify error level to reduce search space.
        Level 1: PHY (Sync, SNR)
        Level 2: MAC (CRC, Schedule)
        Level 3: SYS (Mode Switch, DMA)
        """
        if error_code & 0xF0: # High bits -> System Error
            return "SYS"
        elif error_code & 0x0C: # Mid bits -> MAC Error
            return "MAC"
        else:
            return "PHY"

    # --- New: Graph Quality Metrics ---
    def evaluate_graph_quality(self):
        """
        Optimization: Evaluate graph quality metrics.
        """
        if not self.graph or len(self.graph) == 0:
            print("[Metrics] Graph is empty.")
            return {"density": 0, "avg_degree": 0}
            
        density = nx.density(self.graph)
        avg_degree = sum(dict(self.graph.degree()).values()) / len(self.graph)
        print(f"[Metrics] Graph Density: {density:.4f}")
        print(f"[Metrics] Avg Degree: {avg_degree:.2f}")
        return {"density": density, "avg_degree": avg_degree}

    def retrieve_context(self, error_code, context_data):
        """
        5.3.1 Hybrid Retrieval Strategy (Simplified for Demo)
        """
        # 1. Pre-processing: Pipeline Classification
        error_level = self.pipeline_classification(error_code)
        print(f"[RAG] Error Level Classified: {error_level}")

        print(f"[RAG] Retrieving context for ErrorCode: {error_code}...")
        
        # Simulate Retrieval Latency
        # time.sleep(0.02)
        
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

    def generate_prompt(self, error_node, context_info, runtime_context, error_desc="", history=None):
        """
        5.3.2 Structured Prompt Engineering
        Supports multi-turn history for Agentic RAG.
        """
        # Serialize Graph Context
        graph_text = ""
        for item in context_info:
            props_str = ", ".join([f"{k}={v}" for k, v in item['props'].items() if k != 'label'])
            graph_text += f"Node: {item['id']} ({item['type']}) [{props_str}]\n"
            for rel in item['relations']:
                graph_text += f"  {rel}\n"

        history_text = ""
        if history:
            history_text = "\n[Previous Attempts]\n"
            for i, attempt in enumerate(history):
                history_text += f"Attempt {i+1}: {attempt['action']} -> Result: {attempt['result']}\n"

        prompt = f"""
[Role] You are an expert in FPGA-based communication systems.
[Task] Analyze the following hardware error and generate a fix action.

[Context from Knowledge Graph]
{graph_text}

[Runtime State]
Error: {error_node}
Description: {error_desc}
{history_text}
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
        Includes probabilistic 'Hallucinations' and 'Errors' for realism.
        """
        print("[AI] LLM Thinking...")
        
        # Simulate LLM Hallucination (5% chance)
        if random.random() < 0.05:
            print("[AI] (Simulated Hallucination) Generating invalid register address...")
            return {
                "reason": "I believe register 0x9999 controls the universe.",
                "actions": [{"cmd": "WRITE", "addr": "0x9999", "val": 42}]
            }

        # Simulate Dangerous Action (5% chance)
        if random.random() < 0.05:
            print("[AI] (Simulated Unsafe Action) Suggesting global reset...")
            return {
                "reason": "System state unknown. Suggesting hard reset.",
                "actions": [{"cmd": "RESET", "module": "GLOBAL_CLK_CTRL"}]
            }
        
        # Heuristic 1: Sync Loss + SCS Mismatch -> Fix SCS (Prioritized)
        if "Sync_Loss" in prompt and ("SCS Mismatch" in prompt or ("SCS" in prompt and "Required=30" in prompt)):
            # If context says SCS=15 but Protocol says 30 (implied logic)
            return {
                "reason": "Sync Loss detected. Runtime SCS is 15kHz, but 5G NR FR1 standard (from Graph) requires 30kHz. Correcting SCS configuration.",
                "actions": [
                    {"cmd": "WRITE", "addr": "0x14", "val": 30}, # 0x14 is SCS address (mock)
                    {"cmd": "WRITE", "addr": "0x50", "val": 0xA5A5}
                ]
            }

        # Heuristic 2: Sync Loss + High Threshold/Low SNR -> Lower Threshold
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
                    print(f"  [BLOCK] Illegal Address: {hex(addr)} (Hallucination Detected)")
                    continue
                # Value check (simple)
                if addr == 0x10 and (action["val"] > 1.0 or action["val"] < 0):
                     print(f"  [BLOCK] Invalid Threshold Value: {action['val']}")
                     continue
            
            elif action["cmd"] == "RESET":
                if action["module"] == "GLOBAL_CLK_CTRL":
                    print(f"  [BLOCK] Dangerous Action Intercepted: Reset {action['module']}")
                    continue
                     
            valid_actions.append(action)
            
        return valid_actions
