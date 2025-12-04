import os
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.patches as mpatches

# 获取当前脚本所在目录
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def save_figure(filename):
    filepath = os.path.join(SCRIPT_DIR, filename)
    plt.savefig(filepath, dpi=300, bbox_inches='tight')
    print(f"Generated {filepath}")

def draw_operator_extraction():
    fig, ax = plt.subplots(figsize=(10, 6))
    ax.set_xlim(0, 10)
    ax.set_ylim(0, 8)
    ax.axis('off')

    # 颜色定义 (学术蓝/灰风格)
    color_phy = '#E6F3FF'
    color_filter = '#D1E8FF'
    color_op = '#4A90E2'
    color_text = '#333333'

    # 1. 底层：物理层协议 (宽基座)
    # 使用 FancyBboxPatch 替代 Rectangle 以支持圆角
    rect_phy = patches.FancyBboxPatch((1, 0.5), 8, 2, linewidth=1, edgecolor='black', facecolor=color_phy, boxstyle='round,pad=0.2')
    ax.add_patch(rect_phy)
    ax.text(5, 2.1, "Physical Layer Protocols (Heterogeneous)", ha='center', va='bottom', fontsize=12, fontweight='bold')
    
    # 协议细节
    protocols = ["LTE (4G)\n20MHz, ZC-Seq", "5G NR\n100MHz, SSB", "Wi-Fi 6\n80MHz, L-STF"]
    for i, proto in enumerate(protocols):
        ax.text(2.5 + i*2.5, 1.5, proto, ha='center', va='center', fontsize=10, bbox=dict(facecolor='white', edgecolor='gray', boxstyle='round'))

    # 2. 中层：提取准则 (漏斗过滤)
    # 画一个梯形表示过滤
    polygon = patches.Polygon([[1.5, 2.8], [8.5, 2.8], [7, 4.8], [3, 4.8]], closed=True, facecolor=color_filter, edgecolor='gray', alpha=0.8)
    ax.add_patch(polygon)
    ax.text(5, 3.8, "Extraction Criteria\n(Isomorphism & Density)", ha='center', va='center', fontsize=11, color=color_text)
    
    # 箭头
    ax.arrow(5, 2.6, 0, 0.2, head_width=0.2, head_length=0.1, fc='black', ec='black')

    # 3. 顶层：通用算子 (精炼产物)
    rect_op = patches.Rectangle((3, 5.2), 4, 2, linewidth=2, edgecolor='#2C3E50', facecolor='white', linestyle='--')
    ax.add_patch(rect_op)
    ax.text(5, 7.4, "Symbol-Level Operators (Unified)", ha='center', va='bottom', fontsize=12, fontweight='bold', color='#2C3E50')

    operators = ["Sync Core\n(Matched Filter)", "FFT Core\n(Butterfly)", "Demap Core\n(Min-Dist)"]
    positions = [(3.8, 6.2), (5, 6.2), (6.2, 6.2)]
    
    for i, op in enumerate(operators):
        # 画圆形算子
        circle = patches.Circle((3.7 + i*1.3, 6.2), 0.55, facecolor=color_op, edgecolor='black')
        ax.add_patch(circle)
        ax.text(3.7 + i*1.3, 6.2, op, ha='center', va='center', fontsize=8, color='white', fontweight='bold')

    # 连接线
    ax.arrow(5, 4.8, 0, 0.4, head_width=0.2, head_length=0.1, fc='black', ec='black')

    plt.title("Fig 3-1. Symbol-Level Operator Extraction Methodology", y=-0.05, fontsize=12)
    plt.tight_layout()
    save_figure('fig3_1_operator_extraction.png')

def draw_hardware_architecture():
    fig, ax = plt.subplots(figsize=(12, 7))
    ax.set_xlim(0, 12)
    ax.set_ylim(0, 8)
    ax.axis('off')

    # 区域划分
    # Control Plane
    rect_ctrl = patches.Rectangle((0.5, 5), 11, 2.5, linewidth=1, edgecolor='#E74C3C', facecolor='#FDEDEC', linestyle='--')
    ax.add_patch(rect_ctrl)
    ax.text(1, 7.2, "Control Plane (AXI-Lite)", fontsize=12, fontweight='bold', color='#C0392B')

    # Data Plane
    rect_data = patches.Rectangle((0.5, 0.5), 11, 4, linewidth=1, edgecolor='#2980B9', facecolor='#EBF5FB', linestyle='--')
    ax.add_patch(rect_data)
    ax.text(1, 4.2, "Data Plane (AXI-Stream)", fontsize=12, fontweight='bold', color='#2980B9')

    # 核心模块：Mode Ctrl
    # 使用 FancyBboxPatch 替代 Rectangle 以支持圆角
    box_mode = patches.FancyBboxPatch((4.5, 5.5), 3, 1.5, facecolor='#F5B7B1', edgecolor='black', boxstyle='round')
    ax.add_patch(box_mode)
    ax.text(6, 6.25, "Mode Controller\n(FSM & LUT)", ha='center', va='center', fontweight='bold')

    # 算子模块 (带影子寄存器)
    def draw_operator(x, y, name):
        # 外框
        rect = patches.Rectangle((x, y), 2, 2.5, facecolor='white', edgecolor='black')
        ax.add_patch(rect)
        # 影子寄存器部分
        shadow = patches.Rectangle((x+0.2, y+1.8), 1.6, 0.5, facecolor='#D5D8DC', edgecolor='gray')
        ax.add_patch(shadow)
        ax.text(x+1, y+2.05, "Shadow Regs", ha='center', va='center', fontsize=7)
        # 活跃寄存器部分
        active = patches.Rectangle((x+0.2, y+1.2), 1.6, 0.5, facecolor='#AED6F1', edgecolor='gray')
        ax.add_patch(active)
        ax.text(x+1, y+1.45, "Active Regs", ha='center', va='center', fontsize=7)
        # 运算逻辑
        logic = patches.Rectangle((x+0.2, y+0.2), 1.6, 0.9, facecolor='#5DADE2', edgecolor='black')
        ax.add_patch(logic)
        ax.text(x+1, y+0.65, name, ha='center', va='center', fontweight='bold', color='white')
        
        # 原子更新箭头
        ax.arrow(x+1, y+1.8, 0, -0.1, head_width=0.1, fc='red')

    draw_operator(1.5, 1, "Sync Core")
    draw_operator(5, 1, "FFT Core")
    draw_operator(8.5, 1, "Demap Core")

    # 数据流连线 (粗箭头)
    ax.arrow(3.5, 1.5, 1.5, 0, head_width=0.15, width=0.05, fc='#2E86C1', ec='#2E86C1')
    ax.arrow(7, 1.5, 1.5, 0, head_width=0.15, width=0.05, fc='#2E86C1', ec='#2E86C1')

    # 控制流连线 (细虚线)
    # Mode Ctrl -> Shadow Regs
    ax.annotate("", xy=(2.5, 3.3), xytext=(4.5, 6), arrowprops=dict(arrowstyle="->", linestyle="dashed", color='#C0392B'))
    ax.annotate("", xy=(6, 3.3), xytext=(6, 5.5), arrowprops=dict(arrowstyle="->", linestyle="dashed", color='#C0392B'))
    ax.annotate("", xy=(9.5, 3.3), xytext=(7.5, 6), arrowprops=dict(arrowstyle="->", linestyle="dashed", color='#C0392B'))

    # 全局更新信号
    ax.text(6, 4.8, "Global Config Update Signal", ha='center', va='center', fontsize=9, color='red', style='italic')

    plt.title("Fig 3-2. Decoupled Hardware Architecture with Shadow Register Mechanism", y=-0.05, fontsize=12)
    plt.tight_layout()
    save_figure('fig3_2_hardware_arch.png')

def draw_gantt_chart():
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 5), sharex=True)
    
    # 颜色
    color_lte = '#AED6F1'  # 浅蓝
    color_nr = '#F5B7B1'   # 浅红
    color_reconfig = '#E74C3C' # 深红 (代价)
    color_idle = '#D5D8DC' # 灰色 (等待)

    # 场景数据
    # HEFT: LTE(Init) -> Reconfig -> NR(Urgent) -> Reconfig -> LTE(Future)
    # KG-GA: LTE(Init) -> Idle -> LTE(Future) -> Reconfig -> NR(Urgent)

    # 1. HEFT Plot
    ax1.set_title("(a) Baseline: HEFT Algorithm (Greedy Strategy)", loc='left', fontsize=10)
    ax1.set_ylim(0, 1)
    ax1.set_yticks([])
    ax1.set_ylabel("FFT Resource")
    
    # 初始状态
    ax1.barh(0.5, 10, left=0, height=0.6, color=color_lte, edgecolor='black', label='LTE Task')
    ax1.text(5, 0.5, "Prev LTE", ha='center', va='center', fontsize=8)
    
    # 第一次重构 (T=10)
    ax1.barh(0.5, 20, left=10, height=0.6, color=color_reconfig, hatch='///', edgecolor='black', label='Reconfig')
    ax1.text(20, 0.5, "Switch\nLTE->NR", ha='center', va='center', fontsize=7, color='white')
    
    # 执行 NR (T=30)
    ax1.barh(0.5, 30, left=30, height=0.6, color=color_nr, edgecolor='black', label='NR Task')
    ax1.text(45, 0.5, "Urgent NR", ha='center', va='center', fontsize=8)
    
    # 第二次重构 (T=60) - 假设NR执行30
    ax1.barh(0.5, 20, left=60, height=0.6, color=color_reconfig, hatch='///', edgecolor='black')
    ax1.text(70, 0.5, "Switch\nNR->LTE", ha='center', va='center', fontsize=7, color='white')
    
    # 执行 LTE (T=80)
    ax1.barh(0.5, 30, left=80, height=0.6, color=color_lte, edgecolor='black')
    ax1.text(95, 0.5, "Future LTE", ha='center', va='center', fontsize=8)
    
    # Makespan Line
    ax1.axvline(x=110, color='red', linestyle='--')
    ax1.text(112, 0.8, "Makespan: 110", color='red', fontsize=9)


    # 2. KG-GA Plot
    ax2.set_title("(b) Proposed: KG-GA Algorithm (Global Optimization)", loc='left', fontsize=10)
    ax2.set_ylim(0, 1)
    ax2.set_yticks([])
    ax2.set_ylabel("FFT Resource")
    ax2.set_xlabel("Time (Cycles)")

    # 初始状态
    ax2.barh(0.5, 10, left=0, height=0.6, color=color_lte, edgecolor='black')
    ax2.text(5, 0.5, "Prev LTE", ha='center', va='center', fontsize=8)
    
    # 空闲等待 (T=10 to T=15)
    ax2.barh(0.5, 5, left=10, height=0.6, color=color_idle, edgecolor='gray', linestyle='--', label='Idle Wait')
    ax2.text(12.5, 0.5, "Wait", ha='center', va='center', fontsize=7)
    
    # 执行 LTE (T=15) - 无需重构！
    ax2.barh(0.5, 30, left=15, height=0.6, color=color_lte, edgecolor='black')
    ax2.text(30, 0.5, "Future LTE", ha='center', va='center', fontsize=8)
    
    # 第一次重构 (T=45)
    ax2.barh(0.5, 20, left=45, height=0.6, color=color_reconfig, hatch='///', edgecolor='black')
    ax2.text(55, 0.5, "Switch\nLTE->NR", ha='center', va='center', fontsize=7, color='white')
    
    # 执行 NR (T=65)
    ax2.barh(0.5, 30, left=65, height=0.6, color=color_nr, edgecolor='black')
    ax2.text(80, 0.5, "Urgent NR", ha='center', va='center', fontsize=8)

    # Makespan Line
    ax2.axvline(x=95, color='green', linestyle='--')
    ax2.text(97, 0.8, "Makespan: 95 (-13.6%)", color='green', fontsize=9, fontweight='bold')

    # Legend
    handles, labels = ax1.get_legend_handles_labels()
    # Add Idle to legend manually
    idle_patch = mpatches.Patch(color=color_idle, label='Idle Wait')
    handles.append(idle_patch)
    labels.append('Idle Wait')
    
    fig.legend(handles, labels, loc='upper center', bbox_to_anchor=(0.5, 1.05), ncol=5, fontsize=9)

    plt.tight_layout()
    save_figure('fig3_3_scheduling_comparison.png')

def draw_recursive_window():
    fig, ax = plt.subplots(figsize=(8, 4))
    ax.set_xlim(0, 10)
    ax.set_ylim(0, 5)
    ax.axis('off')

    # 核心公式
    ax.text(5, 4.5, r"$E[n] = E[n-1] + p[n] - p[n-L]$", ha='center', fontsize=14, fontweight='bold')

    # 模块框图
    # 寄存器 E[n-1]
    rect_reg = patches.Rectangle((4, 1.5), 2, 1, facecolor='#D7BDE2', edgecolor='black')
    ax.add_patch(rect_reg)
    ax.text(5, 2, "Reg\nAccumulator", ha='center', va='center')

    # 加法器
    circle_add = patches.Circle((2.5, 2), 0.4, facecolor='white', edgecolor='black')
    ax.add_patch(circle_add)
    ax.text(2.5, 2, "+", ha='center', va='center', fontsize=14)

    # 减法器
    circle_sub = patches.Circle((7.5, 2), 0.4, facecolor='white', edgecolor='black')
    ax.add_patch(circle_sub)
    ax.text(7.5, 2, "-", ha='center', va='center', fontsize=14)

    # 延迟线 (Delay Line)
    rect_delay = patches.Rectangle((2, 3.5), 6, 0.8, facecolor='#A3E4D7', edgecolor='black', linestyle='--')
    ax.add_patch(rect_delay)
    ax.text(5, 3.9, "Circular Buffer Delay Line (Length L)", ha='center', va='center')

    # 连线
    # 输入 p[n]
    ax.arrow(0.5, 2, 1.5, 0, head_width=0.1, fc='black')
    ax.text(0.5, 2.2, "Input p[n]", fontsize=10)
    
    # p[n] -> Delay Line
    ax.arrow(1.5, 2, 0, 1.5, head_width=0.1, fc='black') # Up to delay
    ax.arrow(1.5, 3.9, 0.5, 0, head_width=0.1, fc='black') # Into delay

    # Delay Line -> p[n-L] -> Sub
    ax.arrow(8, 3.9, 0, -1.4, head_width=0.1, fc='black') # Down from delay
    ax.text(8.2, 3, "p[n-L]", fontsize=10)

    # Add -> Reg
    ax.arrow(2.9, 2, 1.1, 0, head_width=0.1, fc='black')
    
    # Reg -> Sub (Feedback E[n-1]) - 这里逻辑有点绕，简化画法
    # 实际上是 E[n] = (E[n-1] + p[n]) - p[n-L] 或者 E[n] = E[n-1] + (p[n] - p[n-L])
    # 画成 E[n-1] 回路
    ax.annotate("", xy=(2.5, 1.5), xytext=(5, 1.5), arrowprops=dict(arrowstyle="->", connectionstyle="angle,angleA=0,angleB=-90,rad=10"))
    
    # Reg -> Output
    ax.arrow(6, 2, 1.1, 0, head_width=0.1, fc='black') # To Sub? No, output
    ax.text(6.5, 2.2, "E[n]", fontsize=10)

    plt.title("Fig 3-4. Recursive Sliding Window Architecture (O(1) Complexity)", y=0.05, fontsize=10)
    plt.tight_layout()
    save_figure('fig3_4_recursive_window.png')

def draw_algorithm_performance_comparison():
    import numpy as np
    # 数据准备
    scenarios = ['Low Load\n(Random-10)', 'High Load\n(Random-50)', 'Greedy Trap\n(Specific)']
    algorithms = ['HEFT', 'DLS', 'KG-GA (Proposed)']
    
    # Normalized Makespan (以HEFT为基准)
    makespan_data = {
        'HEFT': [1.0, 1.0, 1.0],
        'DLS': [0.98, 0.96, 0.95],
        'KG-GA (Proposed)': [0.95, 0.88, 0.86] # KG-GA 在高负载和陷阱场景优势明显
    }
    
    # Reconfiguration Count (绝对值)
    reconfig_data = {
        'HEFT': [12, 45, 2],
        'DLS': [11, 42, 2],
        'KG-GA (Proposed)': [8, 28, 1] # 显著减少重构
    }

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    
    # 设置颜色
    colors = ['#BDC3C7', '#5DADE2', '#E74C3C'] # 灰，蓝，红
    bar_width = 0.25
    index = np.arange(len(scenarios))
    
    # 绘制子图1：Makespan
    for i, algo in enumerate(algorithms):
        ax1.bar(index + i*bar_width, makespan_data[algo], bar_width, label=algo, color=colors[i], edgecolor='black', zorder=3)
    
    ax1.set_ylabel('Normalized Makespan (Lower is Better)', fontsize=10, fontweight='bold')
    ax1.set_title('(a) Overall Performance Comparison (Makespan)', y=-0.15, fontsize=11)
    ax1.set_xticks(index + bar_width)
    ax1.set_xticklabels(scenarios)
    ax1.set_ylim(0, 1.2)
    ax1.grid(axis='y', linestyle='--', alpha=0.7, zorder=0)
    ax1.legend(loc='upper right', fontsize=9)
    
    # 添加数值标签
    for i, algo in enumerate(algorithms):
        for j, val in enumerate(makespan_data[algo]):
            ax1.text(index[j] + i*bar_width, val + 0.02, f"{val:.2f}", ha='center', fontsize=8)

    # 绘制子图2：重构次数
    for i, algo in enumerate(algorithms):
        ax2.bar(index + i*bar_width, reconfig_data[algo], bar_width, label=algo, color=colors[i], edgecolor='black', zorder=3)
        
    ax2.set_ylabel('Reconfiguration Count (Lower is Better)', fontsize=10, fontweight='bold')
    ax2.set_title('(b) Reconfiguration Overhead Comparison', y=-0.15, fontsize=11)
    ax2.set_xticks(index + bar_width)
    ax2.set_xticklabels(scenarios)
    ax2.grid(axis='y', linestyle='--', alpha=0.7, zorder=0)
    
    # 添加数值标签
    for i, algo in enumerate(algorithms):
        for j, val in enumerate(reconfig_data[algo]):
            ax2.text(index[j] + i*bar_width, val + 0.5, str(val), ha='center', fontsize=8)

    plt.suptitle("Fig 3-5. Performance Evaluation of Scheduling Algorithms", fontsize=13, fontweight='bold', y=1.02)
    plt.tight_layout()
    save_figure('fig3_5_algo_performance.png')

if __name__ == "__main__":
    draw_operator_extraction()
    draw_hardware_architecture()
    draw_gantt_chart()
    draw_recursive_window()
    draw_algorithm_performance_comparison()
