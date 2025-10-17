// Top Module - 重构版本
// 整合IFU, IDU, EXU, LSU, RegisterFile
// 清晰的模块化设计，LSU负责所有访存操作
module ysyx_25040109_top (
    input clk,
    input rst,
    input [31:0] p_count_number,
    output [31:0] inst,
    output [31:0] pc,
    `ifdef SYNTHESIS
    input [31:0] yosys_store_load,
    `endif 
    output [31:0] a0_out
);
   
    // ======== 内部信号 ========
    // IFU输出
    wire [31:0] inst_ifu;
    
    // IDU输出
    wire [31:0] imm;
    wire [4:0] rd_addr_idu;
    wire reg_write_en_idu;
    wire [2:0] funct3;
    wire [6:0] funct7;
    wire inst_invalid;
    wire [11:0] csr_addr;
    wire [6:0] opcode;
    
    // RegisterFile输出
    wire [31:0] rs1_data, rs2_data;
    wire [31:0] csr_rdata_from_regfile;
    wire [31:0] mepc_from_regfile;
    wire [31:0] mtvec_from_regfile;
    
    // EXU输出
    wire [31:0] alu_result;
    wire [31:0] next_pc;
    wire [4:0] rd_addr_exu;
    wire reg_write_en_exu;
    wire [31:0] csr_wdata_from_exu;
    wire csr_we_from_exu;
    
    // LSU输出
    wire [31:0] load_result;
    wire is_load;
    wire is_store;
    
    // 写回数据选择
    wire [31:0] writeback_data;
    assign writeback_data = is_load ? load_result : alu_result;

    // 额外的地址信号
    wire [4:0] rs1_addr = inst_ifu[19:15];

    // ======== Trap状态机 ========
    reg trap_state;
    localparam S_NORMAL = 1'b0;
    localparam S_TRAP_MCAUSE = 1'b1;
    wire is_stalled_by_trap = (trap_state == S_TRAP_MCAUSE);  

    wire is_ecall = (opcode == 7'b1110011) && (funct3 == 3'b000) && (csr_addr == 12'h000) && !inst_invalid;

    always @(posedge clk) begin
        if (rst) begin
            trap_state <= S_NORMAL;
        end else begin
            case (trap_state)
                S_NORMAL: begin
                    if (is_ecall) begin
                        trap_state <= S_TRAP_MCAUSE;
                    end
                end
                S_TRAP_MCAUSE: begin
                    trap_state <= S_NORMAL;
                end
                default: trap_state <= S_NORMAL;
            endcase
        end
    end

    // ======== PC寄存器 ========
    wire pc_wen = !is_stalled_by_trap;
    ysyx_25040109_Reg #(32, 32'h80000000) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc),
        .wen(pc_wen)
    );

    // ======== IFU: 取指单元 ========
    ysyx_25040109_IFU ifu (
        .pc(pc),
        `ifdef SYNTHESIS
        .yosys_inst_from_mem(yosys_store_load),
        `endif
        .inst_ifu(inst_ifu)
    );

    // ======== IDU: 译码单元 ========
    ysyx_25040109_IDU idu (
        .inst(inst_ifu),
        .rd_addr(rd_addr_idu),
        .imm(imm),
        .reg_write_en_idu(reg_write_en_idu),
        .funct3(funct3),
        .funct7(funct7),
        .inst_invalid(inst_invalid),
        .csr_addr(csr_addr),
        .opcode(opcode)
    );

    // ======== RegisterFile: 寄存器堆 ========
    wire final_gpr_we = reg_write_en_exu && !is_stalled_by_trap;
    
    wire [11:0] final_csr_waddr;
    wire [31:0] final_csr_wdata;
    wire final_csr_we;

    localparam CSR_MEPC   = 12'h341;
    localparam CSR_MCAUSE = 12'h342;
    
    assign final_csr_we = (is_stalled_by_trap) ? 1'b1 :          
                          (is_ecall)           ? 1'b1 :          
                          csr_we_from_exu;                         

    assign final_csr_waddr = (is_stalled_by_trap) ? CSR_MCAUSE : 
                             (is_ecall)           ? CSR_MEPC   : 
                             csr_addr;                                

    assign final_csr_wdata = (is_stalled_by_trap) ? 32'd11 :       
                             (is_ecall)           ? pc     :        
                             csr_wdata_from_exu;    

    ysyx_25040109_RegisterFile #(5, 32) regfile (
        .clk(clk),
        .rst(rst),
        .pc(pc),
        .wdata(writeback_data),
        .waddr(rd_addr_exu),
        .wen(final_gpr_we),
        .raddr1(inst_ifu[19:15]),
        .raddr2(inst_ifu[24:20]),
        .rdata1(rs1_data),
        .rdata2(rs2_data),
        .a0_out(a0_out),
        .csr_we(final_csr_we),
        .csr_addr(final_csr_waddr),
        .csr_wdata(final_csr_wdata),
        .mepc_out(mepc_from_regfile),
        .mtvec_out(mtvec_from_regfile),
        .csr_rdata(csr_rdata_from_regfile)
    );

    // ======== EXU: 执行单元 ========
    ysyx_25040109_EXU exu (
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .imm(imm),
        .reg_write_in(reg_write_en_idu),
        .rd_addr(rd_addr_idu),
        .pc(pc), 
        .rs1_addr(rs1_addr),
        .opcode(opcode), 
        .funct3(funct3),
        .funct7(funct7),
        .inst_invalid(inst_invalid),
        .alu_result(alu_result),
        .rd_addr_out(rd_addr_exu),
        .reg_write_en_out(reg_write_en_exu),
        .next_pc(next_pc),
        .csr_addr(csr_addr),
        .csr_rdata(csr_rdata_from_regfile),
        .mepc(mepc_from_regfile),
        .mtvec(mtvec_from_regfile),
        .csr_we_out(csr_we_from_exu),
        .csr_wdata_out(csr_wdata_from_exu)
    );

    // ======== LSU: 访存单元 ========
    ysyx_25040109_LSU lsu (
        .clk(clk),
        .rst(rst),
        .mem_addr(alu_result),       // 地址来自EXU的ALU计算结果
        .store_data(rs2_data),       // Store数据来自rs2
        .funct3(funct3),
        .opcode(opcode),
        .inst_invalid(inst_invalid),
        .load_result(load_result),
        `ifdef SYNTHESIS
        .yosys_load_data(yosys_store_load),
        `endif
        .is_load(is_load),
        .is_store(is_store)
    );

    // ======== 输出指令 ========
    assign inst = inst_ifu;

    // ======== 仿真支持 ========
    `ifndef SYNTHESIS
    import "DPI-C" function void difftest_skip_ref();
    import "DPI-C" function int printf_finish(input int inst);  
    import "DPI-C" function void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    import "DPI-C" function void update_decode_state(int pc, int snpc, int dnpc, int inst);
    
    always @(*) begin
        update_decode_state(pc, pc + 32'd4, next_pc, inst_ifu);
    end

    always @(posedge clk) begin
        // 特殊指令跳过difftest
        if (is_load || is_store || is_ecall || is_stalled_by_trap || opcode == 7'b1110011) begin
            difftest_skip_ref();
        end
    end    
   
    always @(posedge clk) begin
        if (!rst) begin
            itrace_print(pc, inst_ifu, 4, p_count_number);
            if (printf_finish(inst_ifu) == 0) begin
                $finish;
            end
        end
    end
    `endif

endmodule
