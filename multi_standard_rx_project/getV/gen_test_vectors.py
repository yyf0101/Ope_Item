
import numpy as np
import os

def qpsk_mod(bits):
    """QPSK modulation: 00->(1+1j), 01->(-1+1j), 11->(-1-1j), 10->(1-1j)"""
    mapping = {
        (0, 0): (1+1j),
        (0, 1): (-1+1j),
        (1, 1): (-1-1j),
        (1, 0): (1-1j)
    }
    symbols = []
    for i in range(0, len(bits), 2):
        symbols.append(mapping[(bits[i], bits[i+1])])
    return np.array(symbols)

def qam16_mod(bits):
    """16QAM modulation (simplified)"""
    # Map 4 bits to complex symbol
    # Real: 00->-3, 01->-1, 11->1, 10->3 (Gray coding example)
    # Simplified: 00->-3, 01->-1, 10->1, 11->3
    def map_dim(b0, b1):
        if b0 == 0 and b1 == 0: return -3
        if b0 == 0 and b1 == 1: return -1
        if b0 == 1 and b1 == 1: return 1
        if b0 == 1 and b1 == 0: return 3
        return 0
    
    symbols = []
    for i in range(0, len(bits), 4):
        re = map_dim(bits[i], bits[i+1])
        im = map_dim(bits[i+2], bits[i+3])
        symbols.append(re + 1j*im)
    return np.array(symbols)

def gen_preamble(mode):
    """Generate a repetitive preamble for autocorrelation detection"""
    # Pattern length L
    if mode == "WiFi":
        L = 16
        reps = 10 # STF has 10 repetitions
    elif mode == "LTE":
        L = 64 # Simplified
        reps = 2
    elif mode == "NR":
        L = 128 # Simplified
        reps = 2
    else:
        L = 16
        reps = 2
        
    # Random pattern
    pattern = np.random.choice([1+1j, -1-1j, 1-1j, -1+1j], L)
    preamble = np.tile(pattern, reps)
    return preamble

def gen_mode_vectors(mode, num_symbols=64, num_antennas=4):
    if mode == "LTE":
        fft_len = 2048
        mod_func = qpsk_mod
        bits_per_sym = 2
    elif mode == "NR":
        fft_len = 4096
        mod_func = qam16_mod
        bits_per_sym = 4
    elif mode == "WiFi":
        fft_len = 256
        mod_func = qpsk_mod
        bits_per_sym = 2
    else:
        raise ValueError("Unknown mode")

    output_dir = "../sim"
    if not os.path.exists(output_dir):
        output_dir = "." 

    for ant in range(num_antennas):
        # Generate Preamble (Same for all antennas for sync, or could be orthogonal)
        # For simplicity, we use same preamble to verify sync combining
        preamble = gen_preamble(mode)
        
        # Generate Data (Different for each antenna - Spatial Multiplexing)
        bits = np.random.randint(0, 2, num_symbols * bits_per_sym)
        data_symbols = mod_func(bits)
        
        # Combine: [Silence] + [Preamble] + [Data]
        silence = np.zeros(20, dtype=complex)
        full_sequence = np.concatenate([silence, preamble, data_symbols])

        # Add some random noise/phase rotation per antenna to simulate channel
        phase_noise = np.exp(1j * np.random.uniform(0, 2*np.pi))
        # full_sequence = full_sequence * phase_noise # Keep simple for now, perfect channel
        
        # Scale
        max_val = np.max(np.abs(full_sequence))
        if max_val > 0:
            full_sequence = full_sequence / max_val
            
        symbols_re = np.clip(np.round(full_sequence.real * 10000), -32768, 32767).astype(np.int16)
        symbols_im = np.clip(np.round(full_sequence.imag * 10000), -32768, 32767).astype(np.int16)

        filename = os.path.join(output_dir, f"{mode}_ant{ant}.txt")
        
        with open(filename, "w") as f:
            for re, im in zip(symbols_re, symbols_im):
                f.write(f"{re} {im}\n")
        print(f"{mode} Ant{ant} generated: {filename}")

if __name__ == "__main__":
    gen_mode_vectors("LTE")
    gen_mode_vectors("NR")
    gen_mode_vectors("WiFi")
