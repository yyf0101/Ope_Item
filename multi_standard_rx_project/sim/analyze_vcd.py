#!/usr/bin/env python3
"""Headless VCD analyzer for multi_standard_rx.
Extracts:
  - First rising time of sync_found_combined
  - First bits_valid_0 after sync
  - Mode transition times (mode_sel changes)
  - Latency per mode segment (sync -> first bits_valid)
Usage:
  python3 analyze_vcd.py wave.vcd
If no filename passed, defaults to wave.vcd in current directory.
"""
import sys
import re
from collections import defaultdict

fname = sys.argv[1] if len(sys.argv) > 1 else 'wave.vcd'

try:
    f = open(fname,'r')
except OSError as e:
    print(f"[ERROR] Cannot open VCD file: {e}")
    sys.exit(1)

code_to_sig = {}
header_done = False
# Signals of interest (logical groups)
TARGETS = {
    'clk':'clk',
    'mode_sel':'mode_sel',
    'sync_combined':'sync_combined',
    'sync_found_combined':'sync_combined',
    'bits_valid':'bits_valid'
}

def match_target(sig_name: str):
    # Strip hierarchy, map indexed bits_valid_* to bits_valid
    base = sig_name.split('/')[-1]
    if base in TARGETS:
        return TARGETS[base]
    if base.startswith('bits_valid'):  # bits_valid_0..3
        return 'bits_valid'
    return None

for line in f:
    line = line.strip()
    if line.startswith('$var'):
        # $var wire 1 ! clk $end
        parts = line.split()
        if len(parts) >= 5:
            code = parts[3]
            sig_name = parts[4]
            tag = match_target(sig_name)
            if tag:
                code_to_sig[code] = tag
    if line.startswith('$enddefinitions'):
        header_done = True
        break

if not header_done:
    print('[ERROR] Invalid VCD: no $enddefinitions')
    sys.exit(1)

# Initialize tracking
sig_values = {t:None for t in TARGETS}
first_sync_time = None
first_bits_time = None
mode_changes = []
current_mode = None
latencies = []
current_segment = {'mode':None,'sync_time':None,'bits_time':None}

cur_time = 0
f_iter = f
for line in f_iter:
    line=line.strip()
    if not line:
        continue
    if line[0] == '#':
        # time marker
        try:
            cur_time = int(line[1:])
        except ValueError:
            continue
        continue
    # Value change: scalar or vector
    if line[0] in '01xz':
        # scalar: e.g. 1!
        val = line[0]
        code = line[1:]
        if code in code_to_sig:
            name = code_to_sig[code]
            sig_values[name] = val
            # Mode tracking (assume mode_sel is multi-bit -> might not appear here; else single bit per bit)
            if name == 'sync_combined' and val == '1':
                if first_sync_time is None:
                    first_sync_time = cur_time
                if current_segment['sync_time'] is None:
                    current_segment['sync_time'] = cur_time
            if name == 'bits_valid' and val == '1':
                if first_bits_time is None:
                    first_bits_time = cur_time
                if current_segment['sync_time'] is not None and current_segment['bits_time'] is None:
                    current_segment['bits_time'] = cur_time
    elif line[0] == 'b':
        # vector: b0101 CODE
        m = re.match(r'b([01xz]+)\s+(\S+)', line)
        if not m:
            continue
        bits, code = m.groups()
        if code in code_to_sig:
            name = code_to_sig[code]
            sig_values[name] = bits
            if name == 'mode_sel':
                # Strip leading zeros for comparison if needed, but VCD usually consistent
                if current_mode != bits:
                    mode_changes.append((cur_time, bits))
                    # Close previous segment if exists
                    if current_segment['mode'] is not None and current_segment['sync_time'] is not None and current_segment['bits_time'] is not None:
                        latencies.append((current_segment['mode'], current_segment['sync_time'], current_segment['bits_time'], current_segment['bits_time']-current_segment['sync_time']))
                    # Start new segment
                    current_segment = {'mode':bits,'sync_time':None,'bits_time':None}
                    current_mode = bits
            if name == 'sync_combined' and '1' in bits:
                 if first_sync_time is None:
                    first_sync_time = cur_time
                 if current_segment['sync_time'] is None:
                    current_segment['sync_time'] = cur_time

# Final segment latency push
if current_segment['mode'] is not None and current_segment['sync_time'] is not None and current_segment['bits_time'] is not None:
    latencies.append((current_segment['mode'], current_segment['sync_time'], current_segment['bits_time'], current_segment['bits_time']-current_segment['sync_time']))

print('=== VCD ANALYSIS SUMMARY ===')
print(f'File: {fname}')
print(f'Found signals mapped: {code_to_sig}')
if first_sync_time is None:
    print('No sync_combined rising edge detected.')
else:
    print(f'First sync_combined time: {first_sync_time}')
if first_bits_time is None:
    print('No bits_valid after sync detected.')
else:
    print(f'First bits_valid time: {first_bits_time}')
    if first_sync_time is not None:
        print(f'Initial latency (bits_valid_0 - sync): {first_bits_time-first_sync_time}')
print('\nMode transitions:')
for t, m in mode_changes:
    print(f'  time {t}: mode_sel={m}')
print('\nPer-mode latencies:')
for mode, st, bt, dt in latencies:
    print(f'  mode={mode} sync_time={st} bits_time={bt} latency={dt}')
print('============================')
