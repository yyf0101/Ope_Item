
module multi_standard_rx(
    input  wire clk,
    input  wire rst,
    input  wire [1:0] mode_sel,
    // 4x4 MIMO Inputs
    input  wire signed [15:0] din_re_0, input wire signed [15:0] din_im_0,
    input  wire signed [15:0] din_re_1, input wire signed [15:0] din_im_1,
    input  wire signed [15:0] din_re_2, input wire signed [15:0] din_im_2,
    input  wire signed [15:0] din_re_3, input wire signed [15:0] din_im_3,
    input  wire din_valid,
    // 4x4 MIMO Outputs
    output wire [7:0] bits_out_0, output wire bits_valid_0,
    output wire [7:0] bits_out_1, output wire bits_valid_1,
    output wire [7:0] bits_out_2, output wire bits_valid_2,
    output wire [7:0] bits_out_3, output wire bits_valid_3,
    output wire sync_found_combined
);
wire [11:0] fft_len;
wire [7:0]  cp_len;
wire [3:0]  mod_type;

mode_ctrl u_mode_ctrl(.clk(clk), .rst(rst), .mode_sel(mode_sel),
                      .fft_len(fft_len), .cp_len(cp_len), .mod_type(mod_type));

// Sync Detect Instances
wire sync_found_0, sync_found_1, sync_found_2, sync_found_3;
wire [15:0] freq_offset_0, freq_offset_1, freq_offset_2, freq_offset_3; // unused now
wire [63:0] corr_E_0, corr_E_1, corr_E_2, corr_E_3;
wire [63:0] total_E_0, total_E_1, total_E_2, total_E_3;

sync_detect u_sync_0(.clk(clk), .rst(rst), .din_re(din_re_0), .din_im(din_im_0), .din_valid(din_valid), .fft_len(fft_len), .sync_found(sync_found_0), .freq_offset(freq_offset_0), .corr_energy_out(corr_E_0), .total_energy_out(total_E_0));
sync_detect u_sync_1(.clk(clk), .rst(rst), .din_re(din_re_1), .din_im(din_im_1), .din_valid(din_valid), .fft_len(fft_len), .sync_found(sync_found_1), .freq_offset(freq_offset_1), .corr_energy_out(corr_E_1), .total_energy_out(total_E_1));
sync_detect u_sync_2(.clk(clk), .rst(rst), .din_re(din_re_2), .din_im(din_im_2), .din_valid(din_valid), .fft_len(fft_len), .sync_found(sync_found_2), .freq_offset(freq_offset_2), .corr_energy_out(corr_E_2), .total_energy_out(total_E_2));
sync_detect u_sync_3(.clk(clk), .rst(rst), .din_re(din_re_3), .din_im(din_im_3), .din_valid(din_valid), .fft_len(fft_len), .sync_found(sync_found_3), .freq_offset(freq_offset_3), .corr_energy_out(corr_E_3), .total_energy_out(total_E_3));

// MIMO Sync Combination (Energy Sum)
/* verilator lint_off WIDTHEXPAND */
wire [65:0] sum_corr_E  = {2'b0,corr_E_0} + {2'b0,corr_E_1} + {2'b0,corr_E_2} + {2'b0,corr_E_3};
wire [65:0] sum_total_E = {2'b0,total_E_0} + {2'b0,total_E_1} + {2'b0,total_E_2} + {2'b0,total_E_3};
/* verilator lint_on WIDTHEXPAND */

reg sync_combined;
always @(posedge clk or posedge rst) begin
    if (rst) sync_combined <= 0;
    else begin
        if (sum_total_E > 66'd4000000) begin // Higher threshold for 4 antennas (extended width)
             if (sum_corr_E > (sum_total_E >> 1))
                sync_combined <= 1;
             else
                sync_combined <= 0;
        end else begin
            sync_combined <= 0;
        end
    end
end

assign sync_found_combined = sync_combined;

// Demapper Instances (Parallel Processing)
demapper u_demap_0(.clk(clk), .rst(rst), .sym_re(din_re_0), .sym_im(din_im_0), .sym_valid(sync_combined), .mod_type(mod_type), .bits_out(bits_out_0), .bits_valid(bits_valid_0));
demapper u_demap_1(.clk(clk), .rst(rst), .sym_re(din_re_1), .sym_im(din_im_1), .sym_valid(sync_combined), .mod_type(mod_type), .bits_out(bits_out_1), .bits_valid(bits_valid_1));
demapper u_demap_2(.clk(clk), .rst(rst), .sym_re(din_re_2), .sym_im(din_im_2), .sym_valid(sync_combined), .mod_type(mod_type), .bits_out(bits_out_2), .bits_valid(bits_valid_2));
demapper u_demap_3(.clk(clk), .rst(rst), .sym_re(din_re_3), .sym_im(din_im_3), .sym_valid(sync_combined), .mod_type(mod_type), .bits_out(bits_out_3), .bits_valid(bits_valid_3));

endmodule
