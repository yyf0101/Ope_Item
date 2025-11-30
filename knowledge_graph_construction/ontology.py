from enum import Enum
from dataclasses import dataclass, field, asdict
from typing import List, Dict, Optional

# --- Entity Types ---

@dataclass
class Entity:
    id: str
    label: str
    properties: Dict = field(default_factory=dict)

@dataclass
class Protocol(Entity):
    label: str = "Protocol"

@dataclass
class Module(Entity):
    label: str = "Module"

@dataclass
class Register(Entity):
    label: str = "Register"

@dataclass
class Error(Entity):
    label: str = "Error"

@dataclass
class Solution(Entity):
    label: str = "Solution"

# --- Relationship Types ---

class RelationType(Enum):
    IMPLEMENTS = "implements"
    CONFIGURES = "configures"
    SUBMODULE_OF = "submodule_of"
    CONNECTS_TO = "connects_to"
    CAUSES = "causes"
    FIXES = "fixes"
    DEPENDS_ON = "depends_on"

@dataclass
class Relationship:
    source_id: str
    target_id: str
    type: RelationType
    properties: Dict = field(default_factory=dict)

