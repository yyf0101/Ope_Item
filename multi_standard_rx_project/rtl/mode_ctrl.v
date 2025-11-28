
module mode_ctrl(
    input  wire        clk,
    input  wire        rst,
    input  wire [1:0]  mode_sel,    // 00=LTE, 01=NR, 10=Wi-Fi
    
    // Global Control
    output reg         tready_global, // 1=Ready, 0=Pause (Drain/Config)
    output reg         config_update, // Pulse to update shadow registers
    
    // Config Parameters (Shadow inputs to operators)
    output reg  [12:0] fft_len,
    output reg  [8:0]  cp_len,
    output reg  [3:0]  mod_type     // 0=QPSK,1=16QAM
);

    // State definitions
    localparam S_RUN    = 3'd0;
    localparam S_DRAIN  = 3'd1;
    localparam S_CONFIG = 3'd2;
    localparam S_WARMUP = 3'd3;
    
    reg [2:0] state;
    reg [1:0] current_mode;
    reg [7:0] timer;

    // Parameter LUT based on requested mode
    always @(*) begin
        case(mode_sel)
            2'b00: begin fft_len=2048; cp_len=144; mod_type=0; end // LTE
            2'b01: begin fft_len=4096; cp_len=288; mod_type=1; end // NR
            2'b10: begin fft_len=256;  cp_len=32;  mod_type=0; end // Wi-Fi
            default: begin fft_len=2048; cp_len=144; mod_type=0; end
        endcase
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= S_RUN;
            current_mode <= 0; // Default LTE
            tready_global <= 1;
            config_update <= 0;
            timer <= 0;
        end else begin
            case(state)
                S_RUN: begin
                    tready_global <= 1;
                    config_update <= 0;
                    // Detect mode change request
                    if (mode_sel != current_mode) begin
                        state <= S_DRAIN;
                        timer <= 20; // Drain time (simulate pipeline flush)
                    end
                end
                S_DRAIN: begin
                    tready_global <= 0; // Block input
                    if (timer == 0) state <= S_CONFIG;
                    else timer <= timer - 1;
                end
                S_CONFIG: begin
                    config_update <= 1; // Trigger atomic update
                    current_mode <= mode_sel;
                    state <= S_WARMUP;
                    timer <= 50; // Warmup time (simulate PLL/AGC lock)
                end
                S_WARMUP: begin
                    config_update <= 0;
                    if (timer == 0) state <= S_RUN;
                    else timer <= timer - 1;
                end
                default: state <= S_RUN;
            endcase
        end
    end
endmodule
