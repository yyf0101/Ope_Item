
#include "Vmulti_standard_rx.h"
#include "verilated.h"
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
    Vmulti_standard_rx *top = new Vmulti_standard_rx;
    vluint64_t sim_time = 0;

    // 加载三种模式的符号
    auto lte_syms = load_symbols("LTE_symbols.txt");
    auto nr_syms  = load_symbols("NR_symbols.txt");
    auto wifi_syms= load_symbols("WiFi_symbols.txt");

    size_t idx = 0;
    auto current_syms = lte_syms;

    top->clk = 0;
    top->rst = 1;
    top->mode_sel = 0; // 初始LTE
    top->eval();
    top->rst = 0;

    while (!Verilated::gotFinish() && sim_time < 20000) {
        top->clk = (sim_time % 2);

        if (sim_time == 1000) { top->mode_sel = 1; current_syms = nr_syms; idx = 0; }
        if (sim_time == 5000) { top->mode_sel = 2; current_syms = wifi_syms; idx = 0; }

        if (idx < current_syms.size()) {
            top->din_re = current_syms[idx].first;
            top->din_im = current_syms[idx].second;
            top->din_valid = 1;
            idx++;
        } else {
            top->din_valid = 0;
        }

        top->eval();

        if (top->bits_valid) {
            std::cout << "Time: " << sim_time
                      << " Mode: " << (int)top->mode_sel
                      << " Bits: " << (int)top->bits_out << std::endl;
        }
        sim_time++;
    }

    delete top;
    return 0;
}
