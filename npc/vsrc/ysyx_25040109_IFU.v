module ysyx_25040109_IFU (
    input             clk,
    input             rst,
    input             fetch_en,
    input  [31:0]     pc,
    output reg fetch_done,
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
            ifu_addr     <= 32'b0; 
            inst_reg <= 32'b0;
            fetch_done <= 0;
        end else begin
            case (state)
                S_IDLE: begin
                    if (fetch_en) begin
                        ifu_reqValid <= 1;
                        ifu_addr <= pc;
                        state <= S_WAIT;
                        fetch_done <= 0;
                        inst_reg     <= inst_reg;
                    end else begin
                        ifu_reqValid <= 0;
                        ifu_addr <= ifu_addr;
                        state    <= S_IDLE;
                        fetch_done <= 0;
                        inst_reg     <= inst_reg;
                    end
                end
                S_WAIT: begin
                    ifu_reqValid <= 0;
                    if (ifu_respValid) begin
                        inst_reg <= ifu_rdata;
                        state <= S_IDLE;
                        fetch_done <= 1;
                    end  else begin
                    state      <= S_WAIT;
                    fetch_done <= 0;       // 完成信号保持为低
                    inst_reg   <= inst_reg;  // 指令寄存器保持不变
                end
                 ifu_addr <= ifu_addr;
                end
            endcase
        end
    end
    assign inst = inst_reg;
endmodule

