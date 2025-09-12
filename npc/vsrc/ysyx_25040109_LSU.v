module ysyx_25040109_LSU (
    input             clk,
    input             rst,
    input             lsu_en,        // 从CPU触发访存
    input             is_load,
    input             is_store,
    input  [2:0]      funct3,        // 用于计算mask和extend
    input  [31:0]     addr,          // 访存地址
    input  [31:0]     wdata_in,      // 写数据 (from rs2)
    output            lsu_done,      // 访存完成
    output [31:0]     rdata,         // 读数据 (未extend)
    // SimpleBus 接口
    output reg        lsu_reqValid,
    output reg [31:0] lsu_addr,
    output reg        lsu_wen,
    output reg [31:0] lsu_wdata,
    output reg [3:0]  lsu_wmask,
    input             lsu_respValid,
    input  [31:0]     lsu_rdata
);

    localparam S_IDLE = 0;
    localparam S_WAIT = 1;
    reg [0:0] state;
    reg [31:0] rdata_reg;
    wire [1:0] byte_sel = addr[1:0];
    wire [3:0] wmask_calc;
    wire [31:0] wdata_shift;

    // 计算wmask和wdata移位 (word对齐)
    assign wmask_calc = (funct3 == 3'b000) ? (4'b0001 << byte_sel) :        // sb
                        (funct3 == 3'b001) ? (4'b0011 << (byte_sel[1] * 2)) : // sh
                        4'b1111;                                             // sw
    // sb: 1字节, sw: 4字节
    assign wdata_shift = (funct3 == 3'b000) ? ( {24'b0, wdata_in[7:0]}  << (byte_sel * 8)) : // sb
                        (funct3 == 3'b001) ? ( {16'b0, wdata_in[15:0]} << (byte_sel[1] * 16)) : // sh
                        wdata_in; // sw


    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            lsu_reqValid <= 0;
            rdata_reg <= 0;
        end else begin
            case (state)
                S_IDLE: begin
                    if (lsu_en) begin
                        lsu_reqValid <= 1;
                        lsu_addr <= addr & 32'hFFFFFFFC;  // word对齐
                        lsu_wen <= is_store;
                        lsu_wdata <= wdata_shift;
                        lsu_wmask <= wmask_calc;
                        state <= S_WAIT;
                    end else begin
                        lsu_reqValid <= 0;
                         lsu_wmask <= 0;
                    end
                end
                S_WAIT: begin
                    lsu_reqValid <= 0;
                    lsu_wen <= 0;
                    if (lsu_respValid) begin
                        if (is_load) begin
                            rdata_reg <= lsu_rdata;
                        end
                        state <= S_IDLE;
                    end
                end
            endcase
        end
    end

    assign lsu_done = (state == S_WAIT) && lsu_respValid;
    assign rdata = rdata_reg;

endmodule


