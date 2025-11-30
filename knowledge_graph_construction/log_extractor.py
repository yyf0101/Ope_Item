import re
from ontology import Error, Relationship, RelationType

class LogExtractor:
    def __init__(self):
        self.templates = [
            {
                "pattern": r"Sync lost at frame (\d+), SNR=(\d+)dB",
                "name": "Sync_Loss",
                "severity": "High"
            },
            {
                "pattern": r"CRC check failed",
                "name": "CRC_Fail",
                "severity": "Medium"
            }
        ]

    def parse_log_line(self, line: str) -> dict:
        results = {
            "entities": [],
            "relationships": []
        }

        for tmpl in self.templates:
            match = re.search(tmpl["pattern"], line)
            if match:
                # Create an Error entity instance
                # In a real system, we might create a unique Event node and link it to the Error Type.
                # Here, per the prompt, we link to an Error entity.
                
                error_id = tmpl["name"]
                error_entity = Error(
                    id=error_id, 
                    properties={
                        "severity": tmpl["severity"], 
                        "symptom": line,
                        "params": match.groups()
                    }
                )
                results["entities"].append(error_entity)
                
                # We can try to infer relationships if we know the context (e.g. from previous static analysis)
                # For now, we just return the error entity.
                
        return results
