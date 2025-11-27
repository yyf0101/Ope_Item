
module demapper(
    input  wire clk,
    input  wire rst,
    input  wire signed [15:0] sym_re,
    input  wire signed [15:0] sym_im,
    input  wire sym_valid,
    input  wire [3:0] mod_type,
    output reg  [7:0] bits_out,
    output reg  bits_valid
);
always @(posedge clk or posedge rst) begin
    if (rst) begin
        bits_out <= 0; bits_valid <= 0;
    end else if (sym_valid) begin
        case(mod_type)
            0: begin // QPSK
                // Python: 00->(1+1j), 01->(-1+1j), 11->(-1-1j), 10->(1-1j)
                // Map: + -> 0, - -> 1
                bits_out[1:0] <= {~(sym_re > 0), ~(sym_im > 0)}; 
            end
            1: begin // 16QAM
                // Python: 00->-3, 01->-1, 10->1, 11->3
                // Thresholds approx 20000 (since 1->10000, 3->30000)
                // Real part
                bits_out[3] <= (sym_re > 0); // MSB: 1 if pos, 0 if neg
                if (sym_re > 0)
                    bits_out[2] <= (sym_re > 20000); // 11 if > 20000
                else
                    bits_out[2] <= (sym_re > -20000); // 01 if > -20000 (i.e. -1)
                
                // Imag part
                bits_out[1] <= (sym_im > 0);
                if (sym_im > 0)
                    bits_out[0] <= (sym_im > 20000);
                else
                    bits_out[0] <= (sym_im > -20000);
            end
        endcase
        bits_valid <= 1;
    end else begin
        bits_valid <= 0;
    end
end
endmodule
