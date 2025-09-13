module ysyx_25040109_LSU (
    input clk,
    input rst,
    input lsu_en, // 从CPU触发访存
    input is_load,
    input is_store,
    input [2:0] funct3, // 用于计算mask和extend
    input [31:0] addr, // 访存地址
    input [31:0] wdata_in, // 写数据 (from rs2)
    output lsu_done, // 访存完成
    output [31:0] rdata, // 读数据 (未extend)
    // SimpleBus 接口
    output reg lsu_reqValid,
    output reg [31:0] lsu_addr,
    output reg lsu_wen,
    output reg [31:0] lsu_wdata,
    output reg [3:0] lsu_wmask,
    output reg [2:0] lsu_rlen,
    input lsu_respValid,
    input [31:0] lsu_rdata
);
    localparam S_IDLE = 0;
    localparam S_WAIT = 1;
    reg [0:0] state;
    reg [31:0] rdata_reg;

    always @(posedge clk) begin
        if (rst) begin
            state <= S_IDLE;
            lsu_reqValid <= 0;
            lsu_addr <= 32'b0;
            lsu_wen <= 0;
            lsu_wdata <= 32'b0;
            lsu_rlen <= 3'b0;
            lsu_wmask <= 4'b0;
            rdata_reg <= 32'b0;
        end else begin
            case (state)
                S_IDLE: begin
                    if (lsu_en) begin
                        lsu_reqValid <= 1;
                        lsu_addr <= addr;  // 直接使用字节地址，无需对齐
                        lsu_wen <= is_store;
                        
                        if (is_store) begin
                            case(funct3)
                                3'b000: begin  // sb
                                    lsu_wdata <= {24'b0, wdata_in[7:0]};
                                    lsu_wmask <= 4'b0001;
                                    lsu_rlen <= 3'd0;  // store无读
                                end
                                3'b010: begin  // sw
                                    lsu_wdata <= wdata_in;
                                    lsu_wmask <= 4'b1111;
                                    lsu_rlen <= 3'd0;
                                end
                                default: begin
                                    lsu_wdata <= 32'b0;
                                    lsu_wmask <= 4'b0;
                                    lsu_rlen <= 3'd0;
                                end
                            endcase
                        end else if (is_load) begin
                            lsu_wdata <= 32'b0;
                            lsu_wmask <= 4'b0;
                            case(funct3)
                                3'b010: lsu_rlen <= 3'd4;  // lw: 读4字节
                                3'b100: lsu_rlen <= 3'd1;  // lbu: 读1字节
                                default: lsu_rlen <= 3'd0;
                            endcase
                        end
                        state <= S_WAIT;
                    end else begin
                        lsu_reqValid <= 0;
                        lsu_rlen <= 0;
                        lsu_wmask <= 0;
                        lsu_addr <= lsu_addr;
                        lsu_wen <= 0;
                        lsu_wdata <= lsu_wdata;
                        state <= S_IDLE;
                    end
                    rdata_reg <= rdata_reg;
                end
                S_WAIT: begin
                    lsu_reqValid <= 0;
                    lsu_wen <= 0;
                    if (lsu_respValid) begin
                        if (is_load) begin
                            rdata_reg <= lsu_rdata;
                        end else begin
                            rdata_reg <= rdata_reg;
                        end
                        state <= S_IDLE;
                    end else begin
                        state <= S_WAIT;
                        rdata_reg <= rdata_reg;
                    end
                    lsu_addr <= lsu_addr;
                    lsu_wdata <= lsu_wdata;
                    lsu_wmask <= lsu_wmask;
                    lsu_rlen <= lsu_rlen;
                end
            endcase
        end
    end
    assign lsu_done = (state == S_WAIT) && lsu_respValid;
    assign rdata = rdata_reg;
endmodule

