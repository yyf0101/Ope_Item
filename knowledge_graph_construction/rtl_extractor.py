import re
import os
from ontology import Module, Register, Relationship, RelationType

class VerilogExtractor:
    def __init__(self):
        pass

    def parse_file(self, file_path: str) -> dict:
        """
        Parses a Verilog file to extract Modules, Ports (as potential Registers/Signals), and Instantiations.
        """
        with open(file_path, 'r') as f:
            content = f.read()

        results = {
            "entities": [],
            "relationships": []
        }

        module_name_match = re.search(r'module\s+(\w+)', content)
        if not module_name_match:
            return results
        
        module_name = module_name_match.group(1)
        module_entity = Module(id=module_name, properties={"file_path": file_path})
        results["entities"].append(module_entity)

        # Extract Inputs/Outputs (Simplified Register/Signal mapping)
        # Looking for inputs that might be config registers (e.g., mode_sel)
        inputs = re.findall(r'input\s+(?:wire|reg)?\s*(?:\[.*?\])?\s*(\w+)', content)
        for inp in inputs:
            # Heuristic: if input name contains 'mode', 'cfg', 'sel', treat as Register/Config
            if any(x in inp for x in ['mode', 'cfg', 'sel', 'threshold']):
                reg_entity = Register(id=f"{module_name}_{inp}", properties={"name": inp, "access": "RO"})
                results["entities"].append(reg_entity)
                results["relationships"].append(Relationship(reg_entity.id, module_entity.id, RelationType.CONFIGURES))

        # Extract Instantiations (Submodules)
        # Pattern: module_name instance_name ( ... )
        # We assume module names start with a letter and are not keywords.
        # This is a simplified regex.
        # We look for "name u_name (" pattern common in the provided code
        instantiations = re.findall(r'(\w+)\s+(u_\w+)\s*\(', content)
        for sub_mod_type, sub_inst_name in instantiations:
            # We assume the sub-module type is the ID of another module
            # We create a relationship. The sub-module entity might be created when parsing that file.
            # Here we just create a placeholder or link if it exists.
            
            # We add the submodule entity just in case it hasn't been parsed yet, 
            # but ideally we merge them later.
            sub_mod_entity = Module(id=sub_mod_type) 
            # Note: In a real graph, we'd check existence. Here we just emit.
            
            results["relationships"].append(Relationship(sub_mod_entity.id, module_entity.id, RelationType.SUBMODULE_OF))
            
            # Also capture the instance specific relationship if needed, but SUBMODULE_OF is usually Type -> Type or Instance -> Parent
            # Let's stick to Type -> Type for the "Module" class in ontology, 
            # or Instance -> Parent. The ontology says "Module: RTL module or operator unit".
            # Let's do: sub_mod_type is a submodule of module_name
            
        return results

    def parse_directory(self, dir_path: str) -> dict:
        all_results = {"entities": [], "relationships": []}
        for root, dirs, files in os.walk(dir_path):
            for file in files:
                if file.endswith(".v"):
                    file_results = self.parse_file(os.path.join(root, file))
                    all_results["entities"].extend(file_results["entities"])
                    all_results["relationships"].extend(file_results["relationships"])
        return all_results
