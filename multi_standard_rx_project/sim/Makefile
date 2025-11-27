### Top module name
TOP               ?= multi_standard_rx

### RTL sources (extendable)
RTL_DIR           ?= ../rtl
RTL_SRCS          := $(RTL_DIR)/$(TOP).v \
                     $(RTL_DIR)/mode_ctrl.v \
                     $(RTL_DIR)/sync_detect.v \
                     $(RTL_DIR)/demapper.v

### Testbench source
TB_CPP            := tb_$(TOP).cpp

### Verilator base flags
BASE_FLAGS        := -Wall --cc --exe --build --trace
SUPPRESS_WARN     := --Wno-WIDTHTRUNC --Wno-UNUSEDSIGNAL --Wno-CASEINCOMPLETE

### Optimization / debug switch (set BUILD=debug for -O0)
ifeq ($(BUILD),debug)
  CXX_OPT        := -O0 -g
else
  CXX_OPT        := -Os
endif
export VERILATOR_CXXFLAGS := $(CXX_OPT)

### Default goal
.PHONY: all sim run run_head wave clean cleanall fast
all: sim

sim: $(RTL_SRCS) $(TB_CPP)
	verilator $(BASE_FLAGS) $(SUPPRESS_WARN) $(RTL_SRCS) $(TB_CPP)

### Standard run (full output)
run: sim
	./obj_dir/V$(TOP)

### Run and only keep first N lines without让 make 失败
N ?= 60
run_head: sim
	./obj_dir/V$(TOP) | head -n $(N) || true

### Run and save log (allows full simulation to complete)
run_log: sim
	./obj_dir/V$(TOP) > sim.log

### Open waveform (requires gtkwave installed)
wave: sim
	gtkwave wave.vcd &

wave_cfg: sim wave.tcl
	gtkwave -T wave.tcl &

### Fast rebuild (clean + sim)
fast: clean sim

analyze: sim
	python3 analyze_vcd.py wave.vcd

clean:
	rm -rf obj_dir *.log

cleanall: clean
	rm -f wave.vcd LTE_*.txt NR_*.txt WiFi_*.txt

### Help
.PHONY: help
help:
	@echo "Targets: sim | run | run_head N=<lines> | wave | fast | clean | cleanall | help"
	@echo "Variables: TOP=<top_module> BUILD=debug|release N=<lines>"