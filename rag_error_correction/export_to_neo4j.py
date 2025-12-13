import json
import os

def escape_string(s):
    if isinstance(s, str):
        return s.replace("'", "\\'").replace('"', '\\"')
    return s

def generate_cypher(json_path, output_cypher_path):
    print(f"Reading graph data from: {json_path}")
    with open(json_path, 'r') as f:
        data = json.load(f)

    nodes = data.get('nodes', [])
    edges = data.get('edges', []) or data.get('links', [])

    print(f"Found {len(nodes)} nodes and {len(edges)} edges.")

    cypher_lines = []
    cypher_lines.append("// Clear existing database (Optional - uncomment to use)")
    cypher_lines.append("// MATCH (n) DETACH DELETE n;")
    cypher_lines.append("")

    # Create Nodes
    print("Generating Cypher for nodes...")
    for node in nodes:
        node_id = node.get('id')
        label = node.get('label', 'Entity')
        # Sanitize label for Cypher (remove spaces, special chars if needed, though usually labels are clean)
        label = "".join(x for x in label if x.isalnum() or x == "_") if label else "Entity"
        
        props = []
        for k, v in node.items():
            if k == 'label': continue # Used as node label
            if isinstance(v, (int, float)):
                props.append(f"{k}: {v}")
            else:
                props.append(f"{k}: '{escape_string(str(v))}'")
        
        props_str = ", ".join(props)
        # Using MERGE to avoid duplicates based on ID
        cypher_lines.append(f"MERGE (n:{label} {{id: '{escape_string(node_id)}'}}) SET n += {{{props_str}}};")

    cypher_lines.append("")
    
    # Create Edges
    print("Generating Cypher for edges...")
    for edge in edges:
        source = edge.get('source')
        target = edge.get('target')
        rel_type = edge.get('type', 'RELATED_TO')
        # Sanitize relationship type
        rel_type = "".join(x for x in rel_type if x.isalnum() or x == "_").upper()

        props = []
        for k, v in edge.items():
            if k in ['source', 'target', 'type']: continue
            if isinstance(v, (int, float)):
                props.append(f"{k}: {v}")
            else:
                props.append(f"{k}: '{escape_string(str(v))}'")
        
        props_str = " {" + ", ".join(props) + "}" if props else ""
        
        # Match source and target, then create relationship
        cypher_lines.append(f"MATCH (a {{id: '{escape_string(source)}'}}), (b {{id: '{escape_string(target)}'}})")
        cypher_lines.append(f"MERGE (a)-[:{rel_type}{props_str}]->(b);")

    with open(output_cypher_path, 'w') as f:
        f.write("\n".join(cypher_lines))
    
    print(f"Cypher import script saved to: {output_cypher_path}")
    print("You can run this script in the Neo4j Browser or via cypher-shell.")

if __name__ == "__main__":
    base_dir = os.path.dirname(os.path.abspath(__file__))
    json_path = os.path.join(base_dir, 'knowledge_db.json')
    cypher_path = os.path.join(base_dir, 'graph_import.cypher')
    
    generate_cypher(json_path, cypher_path)
