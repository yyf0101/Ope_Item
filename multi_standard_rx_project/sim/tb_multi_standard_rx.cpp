#include "Vmulti_standard_rx.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> config;

void load_config(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.good()) {
        std::cout << "[Warning] Config file not found, using defaults." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string value;
            if (std::getline(is_line, value)) {
                try {
                    config[key] = std::stoi(value);
                } catch (...) {
                    continue;
                }
            }
        }
    }
}

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

    // Load Config
    load_config("sim_config.txt");
    int nr_switch_time = config.count("NR_SWITCH_TIME") ? config["NR_SWITCH_TIME"] : 2000;
    int wifi_switch_time = config.count("WIFI_SWITCH_TIME") ? config["WIFI_SWITCH_TIME"] : 10000;
    int scs_param = config.count("SCS") ? config["SCS"] : 15; 
    int snr_param = config.count("SNR") ? config["SNR"] : 20;

    std::cout << "Simulation Config: NR_SWITCH=" << nr_switch_time 
              << ", WIFI_SWITCH=" << wifi_switch_time 
              << ", SCS=" << scs_param 
              << ", SNR=" << snr_param << std::endl;

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

    bool error_reported = false;

    while (!Verilated::gotFinish() && sim_time < 20000) {
        if (sim_time % 2 == 0) {
            top->clk = 0;
            // Drive inputs on falling edge
            if (sim_time == nr_switch_time) { 
                top->mode_sel = 1; 
                current_syms = nr_syms; 
                idx = 0; 
                std::cout << "Switching to NR at time " << sim_time << std::endl;
            }
            if (sim_time == wifi_switch_time) { 
                top->mode_sel = 2; 
                current_syms = wifi_syms; 
                idx = 0; 
                std::cout << "Switching to WiFi at time " << sim_time << std::endl;
            }

            // Mock Error Injection Logic
            // If in NR mode (mode_sel=1) and SCS is not 30, report Sync Loss
            if (top->mode_sel == 1 && scs_param != 30) {
                if (!error_reported && sim_time > nr_switch_time + 100) {
                    std::cout << "[Error] Sync_Loss: SCS Mismatch (Config=" << scs_param << ", Required=30)" << std::endl;
                    error_reported = true; // Report once to avoid flooding log
                }
            }
            // If SNR is too low, report CRC Error
            if (snr_param < 0) {
                 if (!error_reported && sim_time > 100) {
                    std::cout << "[Error] CRC_Error: Low SNR (SNR=" << snr_param << ")" << std::endl;
                    error_reported = true;
                 }
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
