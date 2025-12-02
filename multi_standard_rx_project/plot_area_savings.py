import matplotlib.pyplot as plt
import numpy as np
import os

def plot_area_savings():
    # Data derived from calc_area_savings.py
    # Values in Gate Equivalents (GE)
    
    # Baseline Breakdown
    # Memory: (2048 + 4096 + 256) * 128 * 1.5 * 4 = 4,915,200
    baseline_mem = 4915200
    # Logic: Total (5,063,760) - Memory (4,915,200) = 148,560
    baseline_logic = 148560
    
    # Proposed Breakdown
    # Memory: 4096 * 128 * 1.5 * 4 = 3,145,728
    proposed_mem = 3145728
    # Logic: Total (3,197,724) - Memory (3,145,728) = 51,996
    proposed_logic = 51996 
    
    labels = ['Baseline\n(Independent IP)', 'Proposed\n(Operator Reuse)']
    memory_means = [baseline_mem, proposed_mem]
    logic_means = [baseline_logic, proposed_logic]
    
    width = 0.4       # the width of the bars

    fig, ax = plt.subplots(figsize=(10, 7))

    # Create stacked bars
    # Memory at the bottom
    p1 = ax.bar(labels, memory_means, width, label='Memory (SRAM)', color='#5DADE2', edgecolor='black', alpha=0.9)
    # Logic on top
    p2 = ax.bar(labels, logic_means, width, bottom=memory_means, label='Logic (Gates)', color='#F5B041', edgecolor='black', alpha=0.9)

    # Formatting
    ax.set_ylabel('Area Cost (Gate Equivalents)', fontsize=12)
    ax.set_title('4x4 MIMO Receiver Area Comparison: Baseline vs. Proposed', fontsize=14, fontweight='bold', pad=20)
    ax.legend(loc='upper right', fontsize=10)
    
    # Set y-axis limit to make room for text
    ax.set_ylim(0, (baseline_mem + baseline_logic) * 1.15)
    
    # Add grid
    ax.grid(axis='y', linestyle='--', alpha=0.5)

    # Add value labels
    def add_labels(rects):
        for rect in rects:
            height = rect.get_height()
            # Only label if height is significant enough to be visible
            if height > 200000: 
                ax.text(rect.get_x() + rect.get_width()/2., rect.get_y() + height/2.,
                        f'{height/1000000:.1f}M',
                        ha='center', va='center', color='white', fontweight='bold', fontsize=10)

    add_labels(p1)
    # Logic is too small relative to memory to label inside the bar effectively in this scale, 
    # so we label the total on top.

    # Add total labels on top of bars
    totals = [baseline_mem + baseline_logic, proposed_mem + proposed_logic]
    for i, total in enumerate(totals):
        ax.text(i, total + 100000, f"{total:,.0f} GE", ha='center', fontweight='bold', fontsize=12)

    # Add savings annotation arrow
    savings = totals[0] - totals[1]
    percent = (savings / totals[0]) * 100
    
    # Coordinates for arrow
    x_start = 0
    y_start = totals[0]
    x_end = 1
    y_end = totals[1]
    
    # Draw arrow from Baseline top to Proposed top
    ax.annotate(f'SAVINGS\n{savings/1000000:.2f}M GE\n(-{percent:.1f}%)',
                xy=(x_end, y_end), xycoords='data',
                xytext=(x_start + 0.5, y_start), textcoords='data',
                arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=-0.2", color='green', lw=2.5),
                fontsize=12, color='green', fontweight='bold', ha='center', va='bottom')

    plt.tight_layout()
    
    # Ensure directory exists
    output_dir = 'Operator_Item/multi_standard_rx_project'
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        
    output_path = os.path.join(output_dir, 'area_savings_comparison.png')
    plt.savefig(output_path, dpi=300)
    print(f"Chart saved to {output_path}")

if __name__ == "__main__":
    plot_area_savings()
