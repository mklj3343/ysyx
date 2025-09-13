module ysyx_25040109_cpu (
`ifndef SYNTHESIS
    output [31:0] next_pc,
    output [31:0] pc_out,
    output [31:0] inst_out,
    output [31:0] a0_out,
`endif
    input clk,
    input rst,
    // IFU SimpleBus 接口
    output ifu_reqValid,
    output [31:0] ifu_addr,
    input ifu_respValid,
    input [31:0] ifu_rdata,
    // LSU SimpleBus 接口
    output lsu_reqValid,
    output [31:0] lsu_addr,
    output lsu_wen,
    output [2:0] lsu_rlen,
    output [31:0] lsu_wdata,
    output [3:0] lsu_wmask,
    input lsu_respValid,
    input [31:0] lsu_rdata
);
    
    localparam S_FETCH = 4'b0000;
    localparam S_WAIT_INST = 4'b0001;
    localparam S_DECODE = 4'b0010;
    localparam S_EXECUTE = 4'b0011;
    localparam S_WAIT_MEM = 4'b0100;
    localparam S_WB_LOAD = 4'b0101;
    reg [3:0] state;
    reg [31:0] inst_reg;
    reg [31:0] load_data;
    reg fetch_en;
    reg lsu_en;
       
    reg prev_is_load;
    reg [4:0] prev_rd_addr;
    wire [31:0] pc_current;
    wire [31:0] rs1_data, rs2_data, imm;
    wire [31:0] alu_result;
    wire [31:0] writeback_data;
    wire is_load, is_store;
    wire reg_write_en;
    wire inst_invalid;
    wire [4:0] rd_addr;
    wire [2:0] funct3;
    wire is_add, is_lui, is_jalr, is_csrrw, is_addi;
    wire [11:0] csr_addr;
    wire [31:0] csr_rdata;
    reg [63:0] mcycle_counter;
    wire fetch_done;
    wire [31:0] ifu_inst;
    wire lsu_done;
    wire [31:0] lsu_rdata_internal;
    wire [4:0] rs1_addr = inst_reg[19:15];
    wire [4:0] rs2_addr = inst_reg[24:20];
    wire stall_condition = prev_is_load && (prev_rd_addr != 5'b0) &&
                           ((prev_rd_addr == rs1_addr) || (prev_rd_addr == rs2_addr)) &&
                           !(is_lui || inst_reg[6:0] == 7'b1110011);  // 排除lui和纯csr读

    always @(posedge clk) begin
        if (rst) begin
            mcycle_counter <= 64'd0;
            state <= S_FETCH;
            fetch_en <= 0;
            lsu_en <= 0;
            prev_is_load <= 0;
            prev_rd_addr <= 5'b0;
        end else begin
            mcycle_counter <= mcycle_counter + 1;
            fetch_en <= 0;
            lsu_en <= 0;
            case (state)
                S_FETCH: begin
                    fetch_en <= 1;
                    state <= S_WAIT_INST;
                end
                S_WAIT_INST: begin
                    if (fetch_done) begin
                        inst_reg <= ifu_inst;
                        state <= S_DECODE;
                    end
                end
                S_DECODE: begin
                    if (stall_condition) begin
                        state <= S_DECODE;
                       // prev_is_load <= 0;
                    end else begin
                        state <= S_EXECUTE;
                    end
                end
                S_EXECUTE: begin
                    if (inst_invalid) begin
                        state <= S_FETCH;
                    end else if (is_load || is_store) begin
                        if ((funct3 == 3'b010) && (alu_result[1:0] != 2'b00)) begin  // lw/sw要求字对齐
                            state <= S_FETCH;  // 跳过，未对齐设为invalid
                        end else begin
                            lsu_en <= 1;
                            state <= S_WAIT_MEM;
                        end
                    end else begin
                        state <= S_FETCH;
                    end
                end
                S_WAIT_MEM: begin
                    if (lsu_done) begin
                        if (is_load) begin
                            case (funct3)
                                3'b010: load_data <= lsu_rdata_internal;  // lw
                                3'b100: load_data <= {24'b0, lsu_rdata_internal[7:0]};  // lbu
                                default: load_data <= 32'b0;
                            endcase
                            state <= S_WB_LOAD;
                        end else begin
                            state <= S_FETCH;
                        end
                    end
                end
                S_WB_LOAD: begin
                    state <= S_FETCH;
                    prev_is_load <= 1;
                    prev_rd_addr <= rd_addr;
                end
                default: state <= S_FETCH;
            endcase
        end
    end
`ifndef SYNTHESIS
    assign pc_out = pc_current;
    assign inst_out = inst_reg;
`endif
    wire pc_update_en = ((state == S_EXECUTE) && !(is_load || is_store)) || ((state == S_WAIT_MEM) && lsu_done);
    ysyx_25040109_Reg #(.WIDTH(32), .RESET_VAL(32'h80000000)) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc_current),
        .wen(pc_update_en)
    );
    ysyx_25040109_IDU idu (
        .inst(inst_reg),
        .rd_addr(rd_addr),
        .imm(imm),
        .is_load(is_load),
        .is_store(is_store),
        .reg_write_en(reg_write_en),
        .funct3(funct3),
        .inst_invalid(inst_invalid),
        .is_addi(is_addi),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_jalr(is_jalr),
        .is_csrrw(is_csrrw),
        .csr_addr(csr_addr)
    );
    ysyx_25040109_EXU exu (
        .inst(inst_reg),
        .pc(pc_current),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .imm(imm),
        .alu_result(alu_result),
        .next_pc(next_pc),
        .inst_invalid(inst_invalid),
        .is_addi(is_addi),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_jalr(is_jalr)
    );
    localparam CSR_MCYCLE = 12'hB00;
    localparam CSR_MCYCLEH = 12'hB80;
    assign csr_rdata = (csr_addr == CSR_MCYCLE) ? mcycle_counter[31:0] :
                       (csr_addr == CSR_MCYCLEH) ? mcycle_counter[63:32] : 32'h0;
    assign writeback_data = is_csrrw ? csr_rdata :
                            is_load ? load_data : alu_result;
    wire reg_wen = ((state == S_EXECUTE) && reg_write_en && !inst_invalid && !(is_load || is_store)) ||
                   ((state == S_WB_LOAD) && reg_write_en && !inst_invalid);
    ysyx_25040109_RegisterFile #(.ADDR_WIDTH(5), .DATA_WIDTH(32)) regfile (
        .pc(pc_current),
        .clk(clk),
        .rst(rst),
        .wdata(writeback_data),
        .waddr(rd_addr),
        .wen(reg_wen),
        .raddr1(inst_reg[19:15]),
        .raddr2(inst_reg[24:20]),
        .rdata1(rs1_data),
        .rdata2(rs2_data)
`ifndef SYNTHESIS
        ,.a0_out(a0_out)
`endif
    );
    ysyx_25040109_IFU ifu (
        .clk(clk),
        .rst(rst),
        .fetch_en(fetch_en),
        .pc(pc_current),
        .fetch_done(fetch_done),
        .inst(ifu_inst),
        .ifu_reqValid(ifu_reqValid),
        .ifu_addr(ifu_addr),
        .ifu_respValid(ifu_respValid),
        .ifu_rdata(ifu_rdata)
    );
    ysyx_25040109_LSU lsu (
        .lsu_rlen(lsu_rlen),
        .clk(clk),
        .rst(rst),
        .lsu_en(lsu_en),
        .is_load(is_load),
        .is_store(is_store),
        .funct3(funct3),
        .addr(alu_result),
        .wdata_in(rs2_data),
        .lsu_done(lsu_done),
        .rdata(lsu_rdata_internal),
        .lsu_reqValid(lsu_reqValid),
        .lsu_addr(lsu_addr),
        .lsu_wen(lsu_wen),
        .lsu_wdata(lsu_wdata),
        .lsu_wmask(lsu_wmask),
        .lsu_respValid(lsu_respValid),
        .lsu_rdata(lsu_rdata)
    );
endmodule

