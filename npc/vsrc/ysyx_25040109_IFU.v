module ysyx_25040109_IFU (
    input             clk,
    input             rst,
    input             fetch_en,
    input  [31:0]     pc,
    output            fetch_done,
    output [31:0]     inst,
    output reg        ifu_reqValid,
    output reg [31:0] ifu_addr,
    input             ifu_respValid,
    input  [31:0]     ifu_rdata
);
    localparam S_IDLE = 0;
    localparam S_WAIT = 1;
    reg [0:0] state;
    reg [31:0] inst_reg;

    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            ifu_reqValid <= 0;
            inst_reg <= 0;
        end else begin
            case (state)
                S_IDLE: begin
                    if (fetch_en) begin
                        ifu_reqValid <= 1;
                        ifu_addr <= pc;
                        state <= S_WAIT;
                    end else begin
                        ifu_reqValid <= 0;
                    end
                end
                S_WAIT: begin
                    ifu_reqValid <= 0;
                    if (ifu_respValid) begin
                        inst_reg <= ifu_rdata;
                        state <= S_IDLE;
                    end
                end
            endcase
        end
    end
    assign fetch_done = (state == S_WAIT) && ifu_respValid;
    assign inst = inst_reg;
endmodule

