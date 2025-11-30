import json
import networkx as nx
from ontology import Entity, Relationship

class KnowledgeGraph:
    def __init__(self):
        self.graph = nx.DiGraph()

    def add_entity(self, entity: Entity):
        # Merge properties if node exists
        if self.graph.has_node(entity.id):
            self.graph.nodes[entity.id].update(entity.properties)
            # Ensure label is preserved or updated
            self.graph.nodes[entity.id]['label'] = entity.label
        else:
            self.graph.add_node(entity.id, label=entity.label, **entity.properties)

    def add_relationship(self, rel: Relationship):
        self.graph.add_edge(rel.source_id, rel.target_id, type=rel.type.value, **rel.properties)

    def merge_results(self, extraction_results: dict):
        for entity in extraction_results.get("entities", []):
            self.add_entity(entity)
        for rel in extraction_results.get("relationships", []):
            self.add_relationship(rel)

    def export_to_json(self, file_path: str):
        data = nx.node_link_data(self.graph)
        with open(file_path, 'w') as f:
            json.dump(data, f, indent=2)
        return data

    def get_stats(self):
        return {
            "nodes": self.graph.number_of_nodes(),
            "edges": self.graph.number_of_edges()
        }
