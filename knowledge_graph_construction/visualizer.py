import json

def generate_d3_html(json_data_path: str, output_html_path: str):
    # Read the JSON data to embed it (or we could load it via fetch if running a server)
    # Embedding is safer for a local file opening in browser without CORS issues.
    with open(json_data_path, 'r') as f:
        graph_data = f.read()

    html_content = f"""
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Communication Link Knowledge Graph</title>
    <script src="https://d3js.org/d3.v7.min.js"></script>
    <style>
        body {{ font-family: sans-serif; }}
        #graph {{ width: 100%; height: 800px; border: 1px solid #ccc; }}
        .node {{ stroke: #fff; stroke-width: 1.5px; cursor: pointer; }}
        .link {{ stroke: #999; stroke-opacity: 0.6; }}
        text {{ font-size: 10px; pointer-events: none; }}
        .tooltip {{ position: absolute; background: #f9f9f9; border: 1px solid #d3d3d3; padding: 5px; display: none; }}
    </style>
</head>
<body>
    <h2>Communication Link Knowledge Graph (Chapter 4)</h2>
    <div id="graph"></div>
    <div class="tooltip" id="tooltip"></div>

    <script>
        const data = {graph_data};
        // Compatibility for NetworkX 3.x which might use 'edges' instead of 'links'
        const links = data.links || data.edges || [];

        const width = document.getElementById('graph').clientWidth;
        const height = document.getElementById('graph').clientHeight;

        const color = d3.scaleOrdinal(d3.schemeCategory10);

        const simulation = d3.forceSimulation(data.nodes)
            .force("link", d3.forceLink(links).id(d => d.id).distance(100))
            .force("charge", d3.forceManyBody().strength(-300))
            .force("center", d3.forceCenter(width / 2, height / 2));

        const svg = d3.select("#graph").append("svg")
            .attr("width", width)
            .attr("height", height)
            .call(d3.zoom().on("zoom", (event) => {{
                g.attr("transform", event.transform);
            }}));

        const g = svg.append("g");

        // Arrow marker
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
            .enter().append("line")
            .attr("class", "link")
            .attr("marker-end", "url(#arrow)");

        const node = g.append("g")
            .attr("class", "nodes")
            .selectAll("circle")
            .data(data.nodes)
            .enter().append("circle")
            .attr("class", "node")
            .attr("r", 10)
            .attr("fill", d => color(d.label))
            .call(d3.drag()
                .on("start", dragstarted)
                .on("drag", dragged)
                .on("end", dragended));

        const label = g.append("g")
            .attr("class", "labels")
            .selectAll("text")
            .data(data.nodes)
            .enter().append("text")
            .attr("dx", 12)
            .attr("dy", ".35em")
            .text(d => d.id);

        const linkLabel = g.append("g")
            .attr("class", "link-labels")
            .selectAll("text")
            .data(links)
            .enter().append("text")
            .attr("font-size", "8px")
            .attr("fill", "#555")
            .text(d => d.type);

        node.on("mouseover", function(event, d) {{
            const tooltip = d3.select("#tooltip");
            tooltip.style("display", "block")
                .html(`<strong>${{d.id}}</strong><br>Type: ${{d.label}}<br>${{JSON.stringify(d)}}`)
                .style("left", (event.pageX + 10) + "px")
                .style("top", (event.pageY - 28) + "px");
        }}).on("mouseout", function() {{
            d3.select("#tooltip").style("display", "none");
        }});

        simulation.on("tick", () => {{
            link
                .attr("x1", d => d.source.x)
                .attr("y1", d => d.source.y)
                .attr("x2", d => d.target.x)
                .attr("y2", d => d.target.y);

            node
                .attr("cx", d => d.x)
                .attr("cy", d => d.y);

            label
                .attr("x", d => d.x)
                .attr("y", d => d.y);
                
            linkLabel
                .attr("x", d => (d.source.x + d.target.x) / 2)
                .attr("y", d => (d.source.y + d.target.y) / 2);
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
    </script>
</body>
</html>
    """

    with open(output_html_path, 'w') as f:
        f.write(html_content)
    print(f"Visualization generated at {output_html_path}")
