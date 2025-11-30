import json
from ontology import Protocol, Relationship, RelationType

class ProtocolExtractor:
    def __init__(self):
        pass

    def extract_from_text(self, text: str) -> dict:
        """
        Simulates LLM-based extraction from protocol text.
        In a real scenario, this would call an OpenAI/Azure API.
        Here we return pre-defined structured data based on keywords.
        """
        results = {
            "entities": [],
            "relationships": []
        }

        # Mocking extraction logic based on keywords in the text
        if "5G" in text or "NR" in text:
            p_nr = Protocol(id="5G_NR", properties={"standard_version": "Rel-15", "frequency_band": "FR1"})
            results["entities"].append(p_nr)
            
            if "subcarrier spacing" in text:
                # Extract SCS entity
                p_scs = Protocol(id="Subcarrier_Spacing", properties={"value": "30kHz", "symbol": "Delta f"})
                results["entities"].append(p_scs)
                results["relationships"].append(Relationship(p_nr.id, p_scs.id, RelationType.DEPENDS_ON))

        if "LTE" in text:
            p_lte = Protocol(id="LTE", properties={"standard_version": "Rel-8"})
            results["entities"].append(p_lte)
            
            if "PSS" in text:
                p_pss = Protocol(id="PSS_Detection", properties={"description": "Primary Synchronization Signal"})
                results["entities"].append(p_pss)
                results["relationships"].append(Relationship(p_lte.id, p_pss.id, RelationType.DEPENDS_ON))

        return results

    def extract_3gpp_mock(self):
        """
        Returns a mock extraction result for a standard 3GPP document.
        """
        text = "For 5G NR, the subcarrier spacing configuration mu determines Delta f = 2^mu * 15 kHz."
        return self.extract_from_text(text)
