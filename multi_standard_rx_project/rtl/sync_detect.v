
module sync_detect(
    input  wire clk,
    input  wire rst,
    input  wire signed [15:0] din_re,
    input  wire signed [15:0] din_im,
    input  wire din_valid,
    input  wire [11:0] fft_len,
    output reg  sync_found,
    output reg  [15:0] freq_offset,
    // Export energies for multi-antenna combining
    output wire [63:0] corr_energy_out,
    output wire [63:0] total_energy_out
);

    // Determine delay D based on fft_len
    reg [7:0] delay_len;
    always @(*) begin
        case(fft_len)
            12'd256: delay_len = 16;   // WiFi
            12'd2048: delay_len = 64;  // LTE
            12'd4096: delay_len = 128; // NR
            default: delay_len = 16;
        endcase
    end

    // Input Delay Line (Circular Buffer)
    reg signed [15:0] buf_re [0:127];
    reg signed [15:0] buf_im [0:127];
    reg [6:0] wr_ptr;
    
    wire [6:0] rd_ptr = wr_ptr - delay_len[6:0]; 
    
    // Read from buffer (Async read / Combinational)
    wire signed [15:0] delayed_re = buf_re[rd_ptr];
    wire signed [15:0] delayed_im = buf_im[rd_ptr];

    // Correlation Product (Combinational)
    wire signed [31:0] prod_re = din_re * delayed_re + din_im * delayed_im;
    wire signed [31:0] prod_im = din_im * delayed_re - din_re * delayed_im;
    wire signed [31:0] energy_term = din_re * din_re + din_im * din_im;

    // Delay line for products (Sequential write, Async read)
    reg signed [31:0] prod_re_buf [0:127];
    reg signed [31:0] prod_im_buf [0:127];
    reg signed [31:0] energy_buf [0:127];
    
    wire [6:0] prod_rd_ptr = wr_ptr - delay_len[6:0];

    wire signed [31:0] prod_re_delayed = prod_re_buf[prod_rd_ptr];
    wire signed [31:0] prod_im_delayed = prod_im_buf[prod_rd_ptr];
    wire signed [31:0] energy_delayed  = energy_buf[prod_rd_ptr];

    // Moving Sum Accumulators
    reg signed [47:0] sum_prod_re, sum_prod_im;
    reg signed [47:0] sum_energy;

    // Magnitude Squared Calculation for Detection
    wire [63:0] mag_sq_corr = sum_prod_re*sum_prod_re + sum_prod_im*sum_prod_im;
    wire [63:0] mag_sq_energy = sum_energy * sum_energy;

    assign corr_energy_out  = mag_sq_corr;
    assign total_energy_out = mag_sq_energy;

    integer i;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            wr_ptr       <= 0;
            sum_prod_re  <= 0;
            sum_prod_im  <= 0;
            sum_energy   <= 0;
            sync_found   <= 0;
            freq_offset  <= 0;
            for(i=0; i<128; i=i+1) begin
                buf_re[i]      <= 0; buf_im[i]      <= 0;
                prod_re_buf[i] <= 0; prod_im_buf[i] <= 0;
                energy_buf[i]  <= 0;
            end
        end else if (din_valid) begin
            // 1. Store new sample
            buf_re[wr_ptr] <= din_re;
            buf_im[wr_ptr] <= din_im;

            // 2. Store instantaneous products
            prod_re_buf[wr_ptr] <= prod_re;
            prod_im_buf[wr_ptr] <= prod_im;
            energy_buf[wr_ptr]  <= energy_term;

            // 3. Update sliding sums with sign-extension to 48 bits
            sum_prod_re <= sum_prod_re
                           + {{16{prod_re[31]}}, prod_re}
                           - {{16{prod_re_delayed[31]}}, prod_re_delayed};
            sum_prod_im <= sum_prod_im
                           + {{16{prod_im[31]}}, prod_im}
                           - {{16{prod_im_delayed[31]}}, prod_im_delayed};
            sum_energy  <= sum_energy
                           + {{16{energy_term[31]}}, energy_term}
                           - {{16{energy_delayed[31]}}, energy_delayed};

            // 4. Local detection (optional if using external combining)
            if (sum_energy > 48'd1000000) begin
                if (mag_sq_corr > (mag_sq_energy >> 1)) begin
                    sync_found <= 1'b1;
                end else begin
                    sync_found <= 1'b0;
                end
            end else begin
                sync_found <= 1'b0;
            end

            wr_ptr <= wr_ptr + 1'b1;
        end
    end
endmodule
