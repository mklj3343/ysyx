// ysyx_25040109_IFU.v
module ysyx_25040109_IFU (
    input clk,
    input rst,
    input stall, // 1. 增加 stall 输入端口

    input [31:0] next_pc,
    input pc_update_en,
    output [31:0] pc_current,
    output [31:0] inst_out,
    output reg ifu_valid,

    output [31:0] ifu_raddr,
    input [31:0] ifu_rdata
);

    localparam STATE_IDLE = 1'b0;
    localparam STATE_WAIT = 1'b1;

    reg current_state;
    reg [31:0] inst_reg;

    ysyx_25040109_Reg #(.WIDTH(32), .RESET_VAL(32'h80000000)) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc_current),
        // pc_update_en 已经包含了暂停逻辑，所以这里是正确的
        .wen(pc_update_en) 
    );

    // 2. IFU的内部状态机，在 stall 为高时必须保持静止
    always @(posedge clk) begin
        if (rst) begin
            current_state <= STATE_IDLE;
        end else if (!stall) begin // <== 只有在不暂停时才更新状态
            case(current_state)
                STATE_IDLE: current_state <= STATE_WAIT;
                STATE_WAIT: current_state <= STATE_IDLE;
            endcase
        end
    end

    assign ifu_raddr = pc_current;
    
    // 3. IFU的指令寄存器，同样受 stall 控制
    always @(posedge clk) begin
        if (rst) begin
            inst_reg <= 32'h13; // Reset to a NOP instruction
        end else if (!stall && current_state == STATE_WAIT) begin // <== 只有在不暂停，且状态正确时才更新
            inst_reg <= ifu_rdata;
        end
    end

    assign inst_out = inst_reg;

    always @(*) begin
        ifu_valid = (current_state == STATE_WAIT);
    end
endmodule
