import os
from ontology import RelationType, Relationship
from nlp_extractor import ProtocolExtractor
from rtl_extractor import VerilogExtractor
from log_extractor import LogExtractor
from graph_manager import KnowledgeGraph
from visualizer import generate_d3_html

def main():
    print("Starting Knowledge Graph Construction...")
    
    # 1. Initialize Graph
    kg = KnowledgeGraph()

    # 2. NLP Extraction (Protocol Knowledge)
    print("Extracting Protocol Knowledge...")
    nlp_ext = ProtocolExtractor()
    # Mocking extraction from a 3GPP text snippet
    proto_data = nlp_ext.extract_3gpp_mock()
    kg.merge_results(proto_data)

    # 3. RTL Extraction (Hardware Knowledge)
    print("Extracting Hardware Knowledge from RTL...")
    rtl_ext = VerilogExtractor()
    # Path to the RTL folder
    rtl_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../multi_standard_rx_project/rtl"))
    if os.path.exists(rtl_path):
        rtl_data = rtl_ext.parse_directory(rtl_path)
        kg.merge_results(rtl_data)
    else:
        print(f"Warning: RTL path {rtl_path} not found.")

    # 4. Log Extraction (Dynamic Knowledge)
    print("Extracting Dynamic Knowledge from Logs...")
    log_ext = LogExtractor()
    sample_log = "[Error] Sync lost at frame 1024, SNR=5dB"
    log_data = log_ext.parse_log_line(sample_log)
    kg.merge_results(log_data)

    # 5. Manual Linking (Cross-modal Fusion)
    # In a real system, this is done by Entity Linking algorithms.
    # Here we manually link the "Sync_Loss" error to the "sync_detect" module or "multi_standard_rx"
    # and the Protocol "PSS_Detection" to "sync_detect"
    
    print("Performing Cross-Modal Fusion...")
    
    # Link Protocol -> Module (Implements)
    # "sync_detect" implements "PSS_Detection" (Mock logic)
    kg.add_relationship(Relationship(source_id="sync_detect", target_id="PSS_Detection", type=RelationType.IMPLEMENTS))
    
    # Link Module -> Error (Causes)
    # "sync_detect" failure causes "Sync_Loss"
    kg.add_relationship(Relationship(source_id="sync_detect", target_id="Sync_Loss", type=RelationType.CAUSES))

    # 6. Export and Visualize
    output_json = "knowledge_graph.json"
    output_html = "knowledge_graph.html"
    
    print(f"Exporting graph to {output_json}...")
    kg.export_to_json(output_json)
    
    print(f"Generating visualization at {output_html}...")
    generate_d3_html(output_json, output_html)

    stats = kg.get_stats()
    print(f"Construction Complete. Nodes: {stats['nodes']}, Edges: {stats['edges']}")

if __name__ == "__main__":
    main()
