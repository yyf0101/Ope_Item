# GTKWave auto-load script for multi_standard_rx 4x4 MIMO
# Usage: gtkwave -T wave.tcl
quietly open_vcd wave.vcd
# Add top-level clocks and mode
add wave -noupdate /multi_standard_rx/clk
add wave -noupdate /multi_standard_rx/rst
add wave -noupdate /multi_standard_rx/mode_sel
# Combined sync
add wave -noupdate /multi_standard_rx/sync_found_combined
# Per-antenna sync_found (local)
add wave -noupdate /multi_standard_rx/sync_found_0
add wave -noupdate /multi_standard_rx/sync_found_1
add wave -noupdate /multi_standard_rx/sync_found_2
add wave -noupdate /multi_standard_rx/sync_found_3
# Energies (may be optimized away if not public, adjust if missing)
add wave -noupdate /multi_standard_rx/corr_E_0
add wave -noupdate /multi_standard_rx/corr_E_1
add wave -noupdate /multi_standard_rx/corr_E_2
add wave -noupdate /multi_standard_rx/corr_E_3
add wave -noupdate /multi_standard_rx/total_E_0
add wave -noupdate /multi_standard_rx/total_E_1
add wave -noupdate /multi_standard_rx/total_E_2
add wave -noupdate /multi_standard_rx/total_E_3
# Demapper valid + bits
add wave -noupdate /multi_standard_rx/bits_valid_0
add wave -noupdate /multi_standard_rx/bits_out_0
add wave -noupdate /multi_standard_rx/bits_valid_1
add wave -noupdate /multi_standard_rx/bits_out_1
add wave -noupdate /multi_standard_rx/bits_valid_2
add wave -noupdate /multi_standard_rx/bits_out_2
add wave -noupdate /multi_standard_rx/bits_valid_3
add wave -noupdate /multi_standard_rx/bits_out_3
update
# Optional: set decimal display for energies
setwfattr -decimal /multi_standard_rx/corr_E_0
setwfattr -decimal /multi_standard_rx/corr_E_1
setwfattr -decimal /multi_standard_rx/corr_E_2
setwfattr -decimal /multi_standard_rx/corr_E_3
setwfattr -decimal /multi_standard_rx/total_E_0
setwfattr -decimal /multi_standard_rx/total_E_1
setwfattr -decimal /multi_standard_rx/total_E_2
setwfattr -decimal /multi_standard_rx/total_E_3
# Place an initial marker at time 0
marker add 0 "START"
# You can later add markers at sync_found rising edges to measure latency.
