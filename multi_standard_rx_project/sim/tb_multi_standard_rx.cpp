
#include "Vmulti_standard_rx.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::pair<int16_t,int16_t>> load_symbols(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::pair<int16_t,int16_t>> symbols;
    int re, im;
    while (file >> re >> im) {
        symbols.emplace_back((int16_t)re, (int16_t)im);
    }
    return symbols;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true); // 开启追踪
    Vmulti_standard_rx *top = new Vmulti_standard_rx;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("wave.vcd");
    vluint64_t sim_time = 0;

    // 加载三种模式的符号 (4 Antennas)
    std::vector<std::vector<std::pair<int16_t,int16_t>>> lte_syms(4), nr_syms(4), wifi_syms(4);
    
    for(int i=0; i<4; i++) {
        lte_syms[i] = load_symbols("LTE_ant" + std::to_string(i) + ".txt");
        nr_syms[i]  = load_symbols("NR_ant" + std::to_string(i) + ".txt");
        wifi_syms[i]= load_symbols("WiFi_ant" + std::to_string(i) + ".txt");
    }

    size_t idx = 0;
    auto current_syms = lte_syms;

    top->clk = 0;
    top->rst = 1;
    top->mode_sel = 0; // 初始LTE
    top->eval();
    top->rst = 0;

    while (!Verilated::gotFinish() && sim_time < 20000) {
        if (sim_time % 2 == 0) {
            top->clk = 0;
            // Drive inputs on falling edge
            if (sim_time == 2000) { 
                top->mode_sel = 1; 
                current_syms = nr_syms; 
                idx = 0; 
                std::cout << "Switching to NR at time " << sim_time << std::endl;
            }
            if (sim_time == 10000) { 
                top->mode_sel = 2; 
                current_syms = wifi_syms; 
                idx = 0; 
                std::cout << "Switching to WiFi at time " << sim_time << std::endl;
            }

            // Flow Control: Only send data if tready_global is HIGH
            if (top->tready_global && idx < current_syms[0].size()) {
                top->din_re_0 = current_syms[0][idx].first; top->din_im_0 = current_syms[0][idx].second;
                top->din_re_1 = current_syms[1][idx].first; top->din_im_1 = current_syms[1][idx].second;
                top->din_re_2 = current_syms[2][idx].first; top->din_im_2 = current_syms[2][idx].second;
                top->din_re_3 = current_syms[3][idx].first; top->din_im_3 = current_syms[3][idx].second;
                top->din_valid = 1;
                idx++;
            } else {
                top->din_valid = 0;
                // Keep previous values or zero out? Usually zero out valid is enough.
                // But to be clean:
                top->din_re_0 = 0; top->din_im_0 = 0;
                top->din_re_1 = 0; top->din_im_1 = 0;
                top->din_re_2 = 0; top->din_im_2 = 0;
                top->din_re_3 = 0; top->din_im_3 = 0;
            }
        } else {
            top->clk = 1;
        }

        top->eval();
        tfp->dump(sim_time); // 每个时间步dump

        if (top->clk == 1 && top->bits_valid_0) {
             // Optional: Print some output to verify
             // std::cout << "Time: " << sim_time << " Bits Valid" << std::endl;
        }
        
        sim_time++;
    }

    tfp->close();
    delete tfp;
    delete top;
    return 0;
}
