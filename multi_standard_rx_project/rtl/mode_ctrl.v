
module mode_ctrl(
    input  wire        clk,
    input  wire        rst,
    input  wire [1:0]  mode_sel,    // 00=LTE, 01=NR, 10=Wi-Fi
    output reg  [11:0] fft_len,
    output reg  [7:0]  cp_len,
    output reg  [3:0]  mod_type     // 0=QPSK,1=16QAM
);
always @(posedge clk or posedge rst) begin
    if (rst) begin
        fft_len  <= 1024;
        cp_len   <= 72;
        mod_type <= 0;
    end else begin
        case(mode_sel)
            2'b00: begin fft_len<=2048; cp_len<=144; mod_type<=0; end // LTE
            2'b01: begin fft_len<=4096; cp_len<=288; mod_type<=1; end // NR
            2'b10: begin fft_len<=256;  cp_len<=32;  mod_type<=0; end // Wi-Fi
        endcase
    end
end
endmodule
