import json
import os
import sys

def generate_d3_html(json_data_path: str, output_html_path: str):
    """
    Generates a standalone HTML file with embedded D3.js visualization for the Knowledge Graph.
    """
    print(f"Reading graph data from: {json_data_path}")
    with open(json_data_path, 'r') as f:
        graph_data = json.load(f)
    
    # Convert to JSON string for embedding
    json_str = json.dumps(graph_data)

    # Count nodes and edges for the title
    node_count = len(graph_data.get('nodes', []))
    edge_count = len(graph_data.get('links', [])) or len(graph_data.get('edges', []))

    html_content = f"""
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Knowledge Graph Visualization</title>
    <script src="https://d3js.org/d3.v7.min.js"></script>
    <style>
        body {{ font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; margin: 0; padding: 20px; background-color: #f4f4f4; }}
        h2 {{ color: #333; }}
        #container {{ display: flex; height: 90vh; gap: 20px; }}
        #graph {{ flex: 3; background: white; border-radius: 8px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); overflow: hidden; }}
        #sidebar {{ flex: 1; background: white; border-radius: 8px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); padding: 20px; overflow-y: auto; }}
        .node {{ stroke: #fff; stroke-width: 1.5px; cursor: pointer; }}
        .link {{ stroke: #999; stroke-opacity: 0.6; stroke-width: 2px; cursor: pointer; }}
        .link:hover {{ stroke: #555; stroke-opacity: 1; stroke-width: 3px; }}
        text {{ font-size: 10px; pointer-events: none; user-select: none; }}
        .tooltip {{ position: absolute; background: rgba(0, 0, 0, 0.8); color: white; padding: 8px; border-radius: 4px; pointer-events: none; font-size: 12px; display: none; z-index: 10; }}
        
        /* Legend */
        .legend {{ font-size: 12px; }}
        .legend-item {{ display: flex; align-items: center; margin-bottom: 5px; }}
        .legend-color {{ width: 12px; height: 12px; margin-right: 8px; border-radius: 50%; }}
    </style>
</head>
<body>
    <h2>Knowledge Graph Visualization ({node_count} Nodes, {edge_count} Edges)</h2>
    <div id="container">
        <div id="graph"></div>
        <div id="sidebar">
            <h3>Node Details</h3>
            <p>Click on a node to see details here.</p>
            <div id="details"></div>
            <hr>
            <h3>Legend</h3>
            <div id="legend"></div>
        </div>
    </div>
    <div class="tooltip" id="tooltip"></div>

    <script>
        const data = {json_str};
        const links = data.links || data.edges || [];
        const nodes = data.nodes || [];

        const container = document.getElementById('graph');
        const width = container.clientWidth;
        const height = container.clientHeight;

        // Color scale based on node label/type
        const color = d3.scaleOrdinal(d3.schemeCategory10);

        // Force Simulation
        const simulation = d3.forceSimulation(nodes)
            .force("link", d3.forceLink(links).id(d => d.id).distance(80))
            .force("charge", d3.forceManyBody().strength(-100))
            .force("center", d3.forceCenter(width / 2, height / 2))
            .force("collide", d3.forceCollide(15));

        const svg = d3.select("#graph").append("svg")
            .attr("width", "100%")
            .attr("height", "100%")
            .attr("viewBox", [0, 0, width, height])
            .call(d3.zoom().on("zoom", (event) => {{
                g.attr("transform", event.transform);
            }}));

        const g = svg.append("g");

        // Arrows
        svg.append("defs").selectAll("marker")
            .data(["end"])
            .enter().append("marker")
            .attr("id", "arrow")
            .attr("viewBox", "0 -5 10 10")
            .attr("refX", 15)
            .attr("refY", 0)
            .attr("markerWidth", 6)
            .attr("markerHeight", 6)
            .attr("orient", "auto")
            .append("path")
            .attr("d", "M0,-5L10,0L0,5")
            .attr("fill", "#999");

        const link = g.append("g")
            .attr("class", "links")
            .selectAll("line")
            .data(links)
            .join("line")
            .attr("class", "link")
            .attr("marker-end", "url(#arrow)");

        // Add click handler for links
        link.on("click", (event, d) => {{
            const details = document.getElementById("details");
            let html = "<strong>Edge Details</strong><br>";
            html += "<strong>Source:</strong> " + d.source.id + "<br>";
            html += "<strong>Target:</strong> " + d.target.id + "<br>";
            for (const [key, value] of Object.entries(d)) {{
                if (key !== "source" && key !== "target" && key !== "index") {{
                    html += "<strong>" + key + ":</strong> " + value + "<br>";
                }}
            }}
            details.innerHTML = html;
            
            // Highlight selected link
            d3.selectAll(".link").style("stroke", "#999").style("stroke-width", "2px");
            d3.select(event.currentTarget).style("stroke", "red").style("stroke-width", "4px");
        }});

        const node = g.append("g")
            .attr("class", "nodes")
            .selectAll("circle")
            .data(nodes)
            .join("circle")
            .attr("class", "node")
            .attr("r", 6)
            .attr("fill", d => color(d.label || d.type || "Unknown"))
            .call(d3.drag()
                .on("start", dragstarted)
                .on("drag", dragged)
                .on("end", dragended));

        node.on("click", (event, d) => {{
            const details = document.getElementById("details");
            let html = "<strong>ID:</strong> " + d.id + "<br>";
            for (const [key, value] of Object.entries(d)) {{
                if (key !== "id" && key !== "index" && key !== "x" && key !== "y" && key !== "vx" && key !== "vy") {{
                    html += "<strong>" + key + ":</strong> " + value + "<br>";
                }}
            }}
            details.innerHTML = html;
        }});

        node.append("title")
            .text(d => d.id);

        simulation.on("tick", () => {{
            link
                .attr("x1", d => d.source.x)
                .attr("y1", d => d.source.y)
                .attr("x2", d => d.target.x)
                .attr("y2", d => d.target.y);

            node
                .attr("cx", d => d.x)
                .attr("cy", d => d.y);
        }});

        function dragstarted(event, d) {{
            if (!event.active) simulation.alphaTarget(0.3).restart();
            d.fx = d.x;
            d.fy = d.y;
        }}

        function dragged(event, d) {{
            d.fx = event.x;
            d.fy = event.y;
        }}

        function dragended(event, d) {{
            if (!event.active) simulation.alphaTarget(0);
            d.fx = null;
            d.fy = null;
        }}

        // Legend Generation
        const uniqueLabels = [...new Set(nodes.map(d => d.label || d.type || "Unknown"))];
        const legendDiv = document.getElementById("legend");
        uniqueLabels.forEach(label => {{
            const item = document.createElement("div");
            item.className = "legend-item";
            item.innerHTML = `<div class="legend-color" style="background-color: ${{color(label)}}"></div>${{label}}`;
            legendDiv.appendChild(item);
        }});

    </script>
</body>
</html>
    """
    
    with open(output_html_path, 'w') as f:
        f.write(html_content)
    print(f"Visualization saved to: {output_html_path}")

if __name__ == "__main__":
    # Resolve paths
    current_dir = os.path.dirname(os.path.abspath(__file__))
    json_path = os.path.join(current_dir, "knowledge_db.json")
    html_path = os.path.join(current_dir, "knowledge_graph_view.html")
    
    if not os.path.exists(json_path):
        print(f"Error: {json_path} not found.")
    else:
        generate_d3_html(json_path, html_path)
