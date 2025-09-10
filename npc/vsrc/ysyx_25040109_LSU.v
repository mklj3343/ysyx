module ysyx_25040109_LSU (
    input clk,
    input rst,
    input is_load,
    input is_store,
    input [31:0] alu_result,
    input [31:0] rs2_data,
    input [2:0] funct3,
    input lsu_start,

    output reg [31:0] load_data,
    output reg lsu_done,
    output reg [31:0] lsu_addr,
    output reg lsu_wen,
    output reg [31:0] lsu_wdata,
    output reg [3:0] lsu_wmask,
    input [31:0] lsu_rdata
);

    // ======================= 修改后的正确逻辑 =======================

    // 1. 定义新的三状态状态机
    localparam STATE_IDLE       = 2'b00;
    localparam STATE_WAIT_MEM   = 2'b01; // 等待内存操作的第一个周期
    localparam STATE_WAIT_DONE  = 2'b10; // 内存操作完成，数据已准备好

    reg [1:0] current_state;

    // 2. 重构状态机逻辑
    always @(posedge clk) begin
        if (rst) begin
            current_state <= STATE_IDLE;
        end else begin
            case (current_state)
                STATE_IDLE: begin
                    // 对于load，需要等待，进入WAIT_MEM
                    if (lsu_start && is_load) current_state <= STATE_WAIT_MEM;
                    // 对于store，认为是单周期完成，直接保持IDLE
                    // （lsu_done的组合逻辑会处理store的完成信号）
                end
                STATE_WAIT_MEM: begin
                    // 从等待内存的第一周期进入第二周期
                    current_state <= STATE_WAIT_DONE;
                end
                STATE_WAIT_DONE: begin
                    // 数据已被CPU取走，返回IDLE
                    current_state <= STATE_IDLE;
                end
                default: current_state <= STATE_IDLE;
            endcase
        end
    end

    // 3. 在IDLE状态且lsu_start时，发起对内存的访问
    always @(posedge clk) begin
        if (!rst && current_state == STATE_IDLE && lsu_start) begin
            lsu_addr  <= alu_result;
            lsu_wen   <= is_store;
            lsu_wdata <= rs2_data;
            case (funct3)
                3'b000: lsu_wmask <= 4'b0001 << alu_result[1:0]; // sb
                3'b010: lsu_wmask <= 4'b1111;                   // sw
                default:lsu_wmask <= 4'b0000;
            endcase
        end
    end

    // 4. 重构lsu_done和load_data的组合逻辑
    always @(*) begin
        // 对于store，在IDLE状态收到start信号的当周期就认为完成
        // 对于load，在WAIT_DONE状态（数据已返回）才认为完成
        lsu_done = (current_state == STATE_WAIT_DONE) || (is_store && lsu_start && current_state == STATE_IDLE);

        // 只有在WAIT_DONE状态，lsu_rdata上的数据才是有效的
        if (is_load && current_state == STATE_WAIT_DONE) begin
            case(funct3)
                3'b010: load_data = lsu_rdata; // lw
                3'b100: load_data = {24'b0, lsu_rdata[7:0]}; // lbu
                default: load_data = 32'h0;
            endcase
        end else begin
            load_data = 32'b0;
        end
    end
    // =============================================================

endmodule

