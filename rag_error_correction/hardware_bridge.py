import random
import time

class HardwareInterface:
    """
    Simulates the interface between the CPU (running RAG) and the FPGA/ASIC.
    Implements the CSR registers defined in Table 5-1.
    Includes probabilistic behavior and noise for realistic simulation.
    """
    def __init__(self):
        # Simulated Registers (Memory Map)
        self.registers = {
            # RO Registers
            "ERR_STATUS_REG": 0x00,      # Bit[0]: Sync Loss, Bit[1]: CRC Error, Bit[2]: FIFO Overflow
            "ERR_CONTEXT_REG": 0x00,     # Stores context (e.g., SCS, MCS, SNR)
            
            # RW Registers
            "AGENT_CTRL_REG": 0x00,      # Bit[0]: Enable_AI, Bit[1]: Force_Reset
            "PARAM_SHADOW_BANK": {},     # Dictionary to simulate shadow bank (addr -> val)
            
            # WO Registers
            "UPDATE_TRIGGER": 0x00       # Write Magic Number to trigger update
        }
        
        # Internal State for Simulation
        self.active_params = {
            "SYNC_THRESH": 0.6,
            "SCS": 30, # kHz
            "MCS": 16, # QAM
            "AGC_GAIN": 20 # dB
        }
        
        # Environment State
        self.env_snr = 20.0 # dB
        
        print("Hardware Interface Initialized (Table 5-1 Compliant).")

    def set_env_snr(self, snr):
        self.env_snr = snr
        print(f"[Env] Channel SNR set to {snr} dB")

    def read_csr(self, reg_name):
        """Reads a CSR register."""
        if reg_name in self.registers:
            return self.registers[reg_name]
        else:
            print(f"[HW] Error: Read from unknown register {reg_name}")
            return 0

    def write_csr(self, reg_name, value):
        """Writes to a CSR register."""
        if reg_name == "ERR_STATUS_REG":
            # Write 1 to clear bits
            self.registers["ERR_STATUS_REG"] &= ~value
            print(f"[HW] ERR_STATUS_REG cleared with mask {bin(value)}")
        
        elif reg_name == "UPDATE_TRIGGER":
            if value == 0xA5A5: # Magic Number
                print("[HW] Update Triggered! Loading Shadow Params to Active...")
                self._load_shadow_to_active()
            else:
                print(f"[HW] Invalid Magic Number for Trigger: {hex(value)}")
        
        elif reg_name == "PARAM_SHADOW_BANK":
             # This is a special case for simulation, usually address based
             pass 
             
        elif reg_name in self.registers:
            self.registers[reg_name] = value
            print(f"[HW] Write {reg_name} = {hex(value)}")
        else:
            print(f"[HW] Error: Write to unknown register {reg_name}")

    def write_shadow_param(self, addr, value):
        """Simulates writing to the PARAM_SHADOW_BANK range."""
        self.registers["PARAM_SHADOW_BANK"][addr] = value
        print(f"[HW] Shadow Write: Addr {hex(addr)} = {value}")

    def _load_shadow_to_active(self):
        """Internal hardware logic to update active params from shadow."""
        shadow = self.registers["PARAM_SHADOW_BANK"]
        # Map addresses to internal params (Mock mapping)
        if 0x10 in shadow:
            self.active_params["SYNC_THRESH"] = shadow[0x10]
            print(f"  -> Active SYNC_THRESH updated to {shadow[0x10]}")
        if 0x14 in shadow:
            self.active_params["SCS"] = shadow[0x14]
            print(f"  -> Active SCS updated to {shadow[0x14]}")
        if 0x18 in shadow:
            self.active_params["AGC_GAIN"] = shadow[0x18]
            print(f"  -> Active AGC_GAIN updated to {shadow[0x18]}")
            
        # Simulate hardware response time
        time.sleep(0.01) 

    def trigger_error(self, error_type, context_data):
        """
        Simulates the 'Perception' phase: Hardware detects error and latches context.
        """
        if error_type == "Sync_Loss":
            self.registers["ERR_STATUS_REG"] |= (1 << 0)
            print("\n[HW] INTERRUPT: Sync Loss Detected!")
        elif error_type == "CRC_Error":
            self.registers["ERR_STATUS_REG"] |= (1 << 1)
            print("\n[HW] INTERRUPT: CRC Error Detected!")
        
        # Add noise to context data (e.g. SNR estimation error)
        noisy_context = context_data.copy()
        if "SNR" in noisy_context:
            noise = random.uniform(-1.0, 1.0)
            noisy_context["SNR"] = round(noisy_context["SNR"] + noise, 1)
            
        # Latch Context
        self.registers["ERR_CONTEXT_REG"] = noisy_context
        print(f"[HW] Context Latched (with sensor noise): {noisy_context}")

    def get_error_status(self):
        return self.registers["ERR_STATUS_REG"]

    def get_error_context(self):
        return self.registers["ERR_CONTEXT_REG"]
        
    def check_system_health(self):
        """
        Simulates the physical layer check. 
        Returns True if system is healthy (recovered), False if error persists.
        """
        # Logic: 
        # 1. If SNR is too low (< -8dB), physics prevents recovery regardless of settings.
        if self.env_snr < -8.0:
            print(f"[Phy] SNR {self.env_snr}dB is too low. Link down.")
            return False
            
        # 2. Check Sync Threshold vs SNR
        # If SNR is low (< 0dB) and Threshold is high (> 0.5), Sync fails.
        if self.env_snr < 0 and self.active_params["SYNC_THRESH"] > 0.5:
            print("[Phy] Sync Threshold too high for current SNR. Sync Loss persists.")
            self.registers["ERR_STATUS_REG"] |= (1 << 0) # Re-trigger error
            return False
            
        # 3. Check SCS Mismatch (Assuming 5G NR requires 30kHz)
        if self.active_params["SCS"] != 30:
             print("[Phy] SCS Mismatch (Active=15kHz, Required=30kHz). Sync Loss persists.")
             self.registers["ERR_STATUS_REG"] |= (1 << 0)
             return False
             
        # 4. Check AGC Gain for CRC
        # If SNR is low (< 0dB) and AGC Gain is low (< 25dB), CRC fails.
        if self.env_snr < 0 and self.active_params["AGC_GAIN"] < 25:
            print("[Phy] AGC Gain too low for signal. CRC Error persists.")
            self.registers["ERR_STATUS_REG"] |= (1 << 1)
            return False
            
        print("[Phy] System parameters match channel conditions. Link Stable.")
        return True
