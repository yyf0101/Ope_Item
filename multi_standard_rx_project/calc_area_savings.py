
import sys

def calculate_area_savings():
    # --- 1. Define Unit Costs (Gate Equivalents - GE) ---
    # These are standard industry estimates for 65nm/28nm processes
    GE_REG_BIT = 8.0       # D-Flip Flop
    GE_SRAM_BIT = 1.5      # SRAM bit (much denser than registers)
    GE_ADDER_BIT = 10.0    # 1-bit Full Adder
    GE_MULT_16x16 = 1500.0 # 16x16 Multiplier (approx)
    GE_LOGIC_MISC = 500.0  # Misc control logic per block

    # --- 2. Define Architecture Parameters ---
    NUM_ANTENNAS = 4
    
    # Buffer widths based on RTL:
    # buf_re (16) + buf_im (16) + prod_re (32) + prod_im (32) + energy (32) = 128 bits width
    BUFFER_WIDTH = 128 

    # Logic Complexity per Sync Block (based on RTL analysis):
    # 6 Multipliers (16x16)
    # 6 Accumulators (48-bit adders)
    LOGIC_COST_PER_INSTANCE = (6 * GE_MULT_16x16) + (6 * 48 * GE_ADDER_BIT) + GE_LOGIC_MISC

    # --- 3. Calculate Baseline (Non-Multiplexed) Area ---
    # In a non-multiplexed design, we need separate hardware for each standard
    # because they might need to run concurrently or are just implemented as separate IP blocks.
    
    # LTE Block (2048 FFT)
    mem_lte = 2048 * BUFFER_WIDTH * GE_SRAM_BIT
    logic_lte = LOGIC_COST_PER_INSTANCE
    area_lte_total = NUM_ANTENNAS * (mem_lte + logic_lte)

    # NR Block (4096 FFT)
    mem_nr = 4096 * BUFFER_WIDTH * GE_SRAM_BIT
    logic_nr = LOGIC_COST_PER_INSTANCE
    area_nr_total = NUM_ANTENNAS * (mem_nr + logic_nr)

    # WiFi Block (256 FFT)
    mem_wifi = 256 * BUFFER_WIDTH * GE_SRAM_BIT
    logic_wifi = LOGIC_COST_PER_INSTANCE
    area_wifi_total = NUM_ANTENNAS * (mem_wifi + logic_wifi)

    total_baseline_area = area_lte_total + area_nr_total + area_wifi_total

    # --- 4. Calculate Multiplexed (Proposed) Area ---
    # The multiplexed design reuses the same logic and the largest memory buffer.
    
    # Max buffer size needed is 4096 (covers NR, LTE, and WiFi)
    mem_mux = 4096 * BUFFER_WIDTH * GE_SRAM_BIT
    logic_mux = LOGIC_COST_PER_INSTANCE # Logic is reused!
    
    # Overhead for Mode Control (Muxes, FSM) - estimated 5% of logic
    logic_mux_overhead = logic_mux * 0.05 

    total_mux_area = NUM_ANTENNAS * (mem_mux + logic_mux + logic_mux_overhead)

    # --- 5. Generate Report ---
    savings = total_baseline_area - total_mux_area
    savings_percent = (savings / total_baseline_area) * 100

    print("="*60)
    print("      4x4 MIMO Multi-Standard Receiver Area Analysis      ")
    print("="*60)
    print(f"{'Metric':<30} | {'Value':<15}")
    print("-" * 50)
    print(f"{'Gate Equivalent (GE) Cost':<30} |")
    print(f"{'  - 16x16 Multiplier':<30} | {GE_MULT_16x16:,.0f} GE")
    print(f"{'  - SRAM Bit':<30} | {GE_SRAM_BIT:,.1f} GE")
    print("-" * 50)
    print("BASELINE (Separate IP Cores):")
    print(f"  LTE Area (4 Antennas)        : {area_lte_total:,.0f} GE")
    print(f"  NR Area (4 Antennas)         : {area_nr_total:,.0f} GE")
    print(f"  WiFi Area (4 Antennas)       : {area_wifi_total:,.0f} GE")
    print(f"  TOTAL BASELINE               : {total_baseline_area:,.0f} GE")
    print("-" * 50)
    print("PROPOSED (Multiplexed Operator):")
    print(f"  Shared Memory (Max 4096)     : {NUM_ANTENNAS * mem_mux:,.0f} GE")
    print(f"  Shared Logic (Reused)        : {NUM_ANTENNAS * logic_mux:,.0f} GE")
    print(f"  Mode Control Overhead        : {NUM_ANTENNAS * logic_mux_overhead:,.0f} GE")
    print(f"  TOTAL PROPOSED               : {total_mux_area:,.0f} GE")
    print("="*60)
    print(f"TOTAL AREA SAVINGS             : {savings:,.0f} GE")
    print(f"PERCENTAGE SAVINGS             : {savings_percent:.2f}%")
    print("="*60)
    print("\nInterpretation:")
    print("1. Logic Reuse: Instead of 3 sets of multipliers/adders, we use 1 set.")
    print("2. Memory Reuse: Instead of allocating separate buffers (2048+4096+256),")
    print("   we allocate one buffer of size 4096 and reuse it.")
    print("3. This represents a significant reduction in silicon cost.")

    # Generate Plot Data for Thesis
    import matplotlib.pyplot as plt
    import os

    labels = ['Baseline (Separate)', 'Proposed (Multiplexed)']
    values = [total_baseline_area, total_mux_area]
    
    plt.figure(figsize=(8, 6))
    plt.bar(labels, values, color=['gray', 'green'], width=0.5)
    plt.ylabel('Area Cost (Gate Equivalents)')
    plt.title('Area Savings Analysis: Multi-Standard Receiver')
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    
    # Add text labels
    for i, v in enumerate(values):
        plt.text(i, v, f"{v:,.0f} GE", ha='center', va='bottom')
        
    output_dir = "../thesis_figures"
    os.makedirs(output_dir, exist_ok=True)
    plt.savefig(os.path.join(output_dir, "area_savings.png"))
    print(f"Saved area plot to {output_dir}/area_savings.png")

if __name__ == "__main__":
    calculate_area_savings()
