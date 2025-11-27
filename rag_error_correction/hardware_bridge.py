class HardwareInterface:
    """
    Simulates the interface between the CPU (running RAG) and the FPGA/ASIC.
    """
    def __init__(self):
        # Simulated Registers
        self.registers = {
            "STATUS_REG": 0x00,      # 0: OK, 1: Sync Error, 2: Demod Error
            "CONFIG_SYNC_WIN": 64,   # Default Window Size
            "CONFIG_MOD_TYPE": 1,    # 0: QPSK, 1: 16QAM
            "CONFIG_HO_THR": 10,     # Handover Threshold
            "CONFIG_ACCUM": 0        # 0: Off, 1: On
        }
        print("Hardware Interface Initialized.")

    def read_status(self):
        """
        Reads the current error status from the hardware.
        In reality, this would read a memory-mapped address.
        """
        status_code = self.registers["STATUS_REG"]
        if status_code == 0:
            return "STATUS_OK"
        elif status_code == 1:
            return "ERROR: Sync Timeout in NR Mode"
        elif status_code == 2:
            return "ERROR: High EVM in 16QAM Demodulation"
        else:
            return "ERROR: Unknown"

    def inject_error(self, error_type):
        """
        For simulation: Inject an error to test the system.
        """
        if error_type == "sync_fail":
            self.registers["STATUS_REG"] = 1
        elif error_type == "demod_fail":
            self.registers["STATUS_REG"] = 2
        print(f"\n[HW] Error Injected: {self.read_status()}")

    def apply_fix(self, action_code):
        """
        Translates the RAG 'action_code' into register writes.
        """
        print(f"[HW] Applying Fix: {action_code}")
        
        actions = action_code.split(';')
        for action in actions:
            action = action.strip()
            if action == "SET_SYNC_WINDOW_LARGE":
                self.registers["CONFIG_SYNC_WIN"] = 256
                print("  -> Register Write: CONFIG_SYNC_WIN = 256")
            elif action == "ENABLE_ACCUMULATION":
                self.registers["CONFIG_ACCUM"] = 1
                print("  -> Register Write: CONFIG_ACCUM = 1")
            elif action == "SWITCH_MOD_QPSK":
                self.registers["CONFIG_MOD_TYPE"] = 0
                print("  -> Register Write: CONFIG_MOD_TYPE = 0 (QPSK)")
            elif action == "ENABLE_CFO_CORRECTION":
                print("  -> Register Write: CFO_EN = 1")
            else:
                print(f"  -> Unknown Action: {action}")
        
        # Clear Error after fix
        self.registers["STATUS_REG"] = 0
        print("[HW] Error Cleared. System Recovered.")
