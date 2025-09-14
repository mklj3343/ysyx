`timescale 1ns / 1ps

// CPU 主模块
module minitv_cpu (
    output reg [31:0] a0_out,
    output reg [31:0] inst_top,
    output reg [31:0] ifu_idu_pc_top,
    output reg [31:0] inst_pc_exu_top,

    input wire clk,
    input wire rst,
    // IFU 访存接口
    output wire [31:0] ifu_addr,
    input wire [31:0] ifu_data,
    output wire ifu_valid,
    input wire ifu_ready,
    // LSU 访存接口
    output wire [31:0] lsu_addr,
    output wire [31:0] lsu_wdata,
    input wire [31:0] lsu_rdata,
    output wire [1:0] lsu_op, // 00: idle, 01: lw, 10: lbu, 11: sw/sb (修正为区分)
    output wire lsu_valid,
    input wire lsu_ready
);


    always @(*) begin
        inst_top = ifu_idu_inst;
        ifu_idu_pc_top = ifu_idu_pc;
        inst_pc_exu_top = idu_exu_pc;
    
    end 



    assign ifu_valid = ifu_idu_valid;

    // IFU 到 IDU 的接口
    wire [31:0] ifu_idu_inst;
    wire ifu_idu_valid;
    wire idu_ifu_ready;
    wire [31:0] ifu_idu_pc; 

    // IDU 到 EXU 的接口
    wire [31:0] idu_exu_rs1_data;
    wire [31:0] idu_exu_rs2_data;
    wire [4:0] idu_exu_rs1_addr;
    wire [4:0] idu_exu_rs2_addr;
    wire [4:0] idu_exu_rd_addr;
    wire [31:0] idu_exu_imm;
    wire [3:0] idu_exu_alu_op;
    wire [1:0] idu_exu_mem_op;
    wire idu_exu_reg_write;
    wire idu_exu_jalr;
    wire [31:0] idu_exu_pc; 
    wire idu_exu_valid;
    wire exu_idu_ready;

    // EXU 到 LSU 的接口
    wire [31:0] exu_lsu_addr;
    wire [31:0] exu_lsu_wdata;
    wire [1:0] exu_lsu_mem_op;
    wire exu_lsu_valid;
    wire lsu_exu_ready;
    wire [4:0] exu_lsu_rd_addr;  // 新增：传递rd_addr到LSU

    // EXU 到 Regfile 的接口
    wire [4:0] exu_regfile_rd_addr;
    wire [31:0] exu_regfile_rd_data;
    wire exu_regfile_write;


    // LSU 到 Regfile 的接口
    wire [4:0] lsu_regfile_rd_addr;
    wire [31:0] lsu_regfile_rd_data;
    wire lsu_regfile_write;

        
    wire jump_flag_from_exu;
    wire [31:0] jump_addr_from_exu;

    // 实例化模块
    ifu u_ifu (
        .clk(clk),
        .rst(rst),
        .idu_ready(idu_ifu_ready),
        .inst(ifu_idu_inst),
        .ifu_valid(ifu_idu_valid),
        .ifu_addr(ifu_addr),
        .ifu_data(ifu_data),
        .ifu_ready(ifu_ready),
        .jump_flag_from_exu(jump_flag_from_exu),
        .jump_addr_from_exu(jump_addr_from_exu),
        .inst_pc(ifu_idu_pc)
    );

    idu u_idu (
        .clk(clk),
        .rst(rst),
        .inst(ifu_idu_inst),
        .ifu_valid(ifu_idu_valid),
        .idu_ready(idu_ifu_ready),
        .exu_ready(exu_idu_ready),
        .inst_pc_from_ifu(ifu_idu_pc),
        .rs1_addr(idu_exu_rs1_addr),
        .rs2_addr(idu_exu_rs2_addr),
        .rd_addr(idu_exu_rd_addr),
        .imm(idu_exu_imm),
        .alu_op(idu_exu_alu_op),
        .mem_op(idu_exu_mem_op),
        .reg_write(idu_exu_reg_write),
        .jalr(idu_exu_jalr),
        .idu_valid(idu_exu_valid),
        .inst_pc_to_exu(idu_exu_pc) 
    );

    exu u_exu (
        .clk(clk),
        .rst(rst),
        .rs1_data(idu_exu_rs1_data),
        .rs2_data(idu_exu_rs2_data),
        .rd_addr(idu_exu_rd_addr),
        .imm(idu_exu_imm),
        .alu_op(idu_exu_alu_op),
        .mem_op(idu_exu_mem_op),
        .reg_write(idu_exu_reg_write),
        .jalr(idu_exu_jalr),
        .idu_valid(idu_exu_valid),
        .inst_pc_from_idu(idu_exu_pc),
        .exu_ready(exu_idu_ready),
        .lsu_addr(exu_lsu_addr),
        .lsu_wdata(exu_lsu_wdata),
        .lsu_mem_op(exu_lsu_mem_op),
        .lsu_valid(exu_lsu_valid),
        .lsu_ready(lsu_exu_ready),
        .lsu_rd_addr(exu_lsu_rd_addr),  // 新增输出
        .regfile_rd_addr(exu_regfile_rd_addr),
        .regfile_rd_data(exu_regfile_rd_data),
        .regfile_write(exu_regfile_write),
        .jump_flag_from_exu(jump_flag_from_exu),
        .jump_addr_from_exu(jump_addr_from_exu)
    );

    lsu u_lsu (
        .clk(clk),
        .rst(rst),
        .addr(exu_lsu_addr),
        .wdata(exu_lsu_wdata),
        .mem_op(exu_lsu_mem_op),
        .exu_valid(exu_lsu_valid),
        .lsu_ready(lsu_exu_ready),
        .rd_addr(exu_lsu_rd_addr),  // 新增输入
        .mem_addr(lsu_addr),
        .mem_wdata(lsu_wdata),
        .mem_rdata(lsu_rdata),
        .mem_op_out(lsu_op),
        .mem_valid(lsu_valid),
        .mem_ready(lsu_ready),
        .regfile_rd_addr(lsu_regfile_rd_addr),
        .regfile_rd_data(lsu_regfile_rd_data),
        .regfile_write(lsu_regfile_write)
    );

    regfile u_regfile (
        .wb_pc(idu_exu_pc),
        .a0_out(a0_out),
        .clk(clk),
        .rst(rst),
        .rs1_addr(idu_exu_rs1_addr),
        .rs2_addr(idu_exu_rs2_addr),
        .rs1_data(idu_exu_rs1_data),
        .rs2_data(idu_exu_rs2_data),
        .exu_rd_addr(exu_regfile_rd_addr),
        .exu_rd_data(exu_regfile_rd_data),
        .exu_write(exu_regfile_write),
        .lsu_rd_addr(lsu_regfile_rd_addr),
        .lsu_rd_data(lsu_regfile_rd_data),
        .lsu_write(lsu_regfile_write)
    );

endmodule

// Regfile 模块（修改：读为组合逻辑+转发）
`timescale 1ns / 1ps
module regfile (
    `ifndef SYNTHESIS
    output [31:0] a0_out,
    input wire [31:0] wb_pc,
    `endif
    input wire clk,
    input wire rst,
    input wire [4:0] rs1_addr,
    input wire [4:0] rs2_addr,
    output wire [31:0] rs1_data,  // 改为wire
    output wire [31:0] rs2_data,  // 改为wire
    input wire [4:0] exu_rd_addr,
    input wire [31:0] exu_rd_data,
    input wire exu_write,
    input wire [4:0] lsu_rd_addr,
    input wire [31:0] lsu_rd_data,
    input wire lsu_write
);
    reg [31:0] registers [0:15]; // RV32E: 16 GPRs

    `ifndef SYNTHESIS
    import "DPI-C" function void update_cpu_state(input int pc, input logic [31:0] regs[]);
    `endif

    integer i;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (i = 0; i < 16; i = i + 1) begin
                registers[i] <= 32'h0;
            end
        end else begin
            if (exu_write && exu_rd_addr != 5'h0) begin
                registers[exu_rd_addr[3:0]] <= exu_rd_data;
            end
            if (lsu_write && lsu_rd_addr != 5'h0) begin
                registers[lsu_rd_addr[3:0]] <= lsu_rd_data;
            end
                    
            `ifndef SYNTHESIS
            update_cpu_state(wb_pc, registers);
            `endif
        end
    end

    // 组合读 + 转发逻辑
    assign rs1_data = (rs1_addr == 5'h0) ? 32'h0 :
                      (rs1_addr == lsu_rd_addr && lsu_write) ? lsu_rd_data :  // 优先LSU转发（load）
                      (rs1_addr == exu_rd_addr && exu_write) ? exu_rd_data :  // 次之EXU转发
                      registers[rs1_addr[3:0]];

    assign rs2_data = (rs2_addr == 5'h0) ? 32'h0 :
                      (rs2_addr == lsu_rd_addr && lsu_write) ? lsu_rd_data :
                      (rs2_addr == exu_rd_addr && exu_write) ? exu_rd_data :
                      registers[rs2_addr[3:0]];

    assign a0_out = registers[10];  // a0是x10
endmodule

// LSU 模块（新增rd_addr输入）
`timescale 1ns / 1ps
module lsu (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    input wire [31:0] wdata,
    input wire [1:0] mem_op,
    input wire exu_valid,
    output reg lsu_ready,
    input wire [4:0] rd_addr,  // 新增：从EXU接收
    output reg [31:0] mem_addr,
    output reg [31:0] mem_wdata,
    input wire [31:0] mem_rdata,
    output reg [1:0] mem_op_out,
    output reg mem_valid,
    input wire mem_ready,
    output reg [4:0] regfile_rd_addr,
    output reg [31:0] regfile_rd_data,
    output reg regfile_write
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            lsu_ready <= 1'b1;
            mem_valid <= 1'b0;
            regfile_write <= 1'b0;
            mem_addr <= 32'h0;
            mem_wdata <= 32'h0;
            mem_op_out <= 2'h0;
            regfile_rd_addr <= 5'h0;
            regfile_rd_data <= 32'h0;
        end else if (exu_valid && mem_ready) begin
            lsu_ready <= 1'b0;
            mem_valid <= 1'b1;
            mem_addr <= addr;
            mem_wdata <= wdata;
            mem_op_out <= mem_op;
            regfile_rd_addr <= rd_addr;  // 修正：从EXU的rd_addr设置
            regfile_write <= (mem_op == 2'b01 || mem_op == 2'b10); // 01: lw, 10: lbu
            regfile_rd_data <= (mem_op == 2'b01) ? mem_rdata :
                               (mem_op == 2'b10) ? {{24{1'b0}}, mem_rdata[7:0]} : 32'h0;
        end else begin
            lsu_ready <= 1'b1;
            mem_valid <= 1'b0;
            regfile_write <= 1'b0;
        end
    end
endmodule

// LSU_MEM 模块（修正op case，假设00:sb,01:lw,10:lbu,11:sw）
`timescale 1ns / 1ps
module lsu_mem (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    input wire [31:0] wdata,
    output reg [31:0] rdata,
    input wire [1:0] op, // 00: sb, 01: lw, 10: lbu, 11: sw
    input wire lsu_valid,
    output reg ready
);

    `ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr, input int len);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
    `endif

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rdata <= 32'h0;
            ready <= 1'b1;
        end else if (lsu_valid) begin
            ready <= 1'b0;
            case (op)
                2'b01: begin // lw
                    `ifndef SYNTHESIS
                    rdata <= verilog_pmem_read(addr,4);
                    `else
                    rdata <= 32'h0;
                    `endif
                end
                2'b10: begin // lbu
                    `ifndef SYNTHESIS
                    rdata <= verilog_pmem_read(addr,1);
                    `else
                    rdata <= 32'h0;
                    `endif
                end
                2'b11: begin // sw
                    `ifndef SYNTHESIS
                    verilog_pmem_write(addr, wdata, 4);
                    `endif
                end
                2'b00: begin // sb
                    `ifndef SYNTHESIS
                    verilog_pmem_write(addr, wdata, 1);
                    `endif
                end
                default: begin
                    rdata <= 32'h0;
                end
            endcase
            ready <= 1'b1;
        end else begin
            ready <= 1'b1;
        end
    end

endmodule

// IFU 模块（无重大改动）
`timescale 1ns / 1ps
module ifu (
    input wire clk,
    input wire rst,
    input wire idu_ready,
    output reg [31:0] inst,
    output reg ifu_valid,

    output wire [31:0] ifu_addr,
    input wire [31:0] ifu_data,
    input wire ifu_ready,
    
    input wire jump_flag_from_exu,
    input wire [31:0] jump_addr_from_exu,
        
    output reg [31:0] inst_pc 
);
    reg [31:0] pc;
    assign ifu_addr = pc;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h80000000;
            inst_pc <= 32'h80000000;
            ifu_valid <= 1'b0;
            inst <= 32'h0;
        end else if (idu_ready && ifu_ready) begin
            inst_pc <= pc;
            inst <= ifu_data;
            ifu_valid <= 1'b1;
            if(jump_flag_from_exu) begin
                pc <= jump_addr_from_exu;
            end else begin
                pc <= pc + 4;
            end
        end else begin
            ifu_valid <= 1'b0;
        end
    end
endmodule

// IFU_MEM 模块（无改动）
`timescale 1ns / 1ps
module ifu_mem (
    input wire clk,
    input wire rst,
    input wire [31:0] addr,
    output reg [31:0] rdata,
    input wire valid,
    output reg ready
);

    `ifndef SYNTHESIS
    import "DPI-C" function int verilog_pmem_read(input int addr, input int len);
    `endif

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rdata <= 32'h0;
            ready <= 1'b1;
        end else if (valid) begin
            ready <= 1'b0;
            `ifndef SYNTHESIS
            rdata <= verilog_pmem_read(addr, 4);
            `else
            rdata <= 32'h0; // 综合时返回 0
            `endif
            ready <= 1'b1;
        end else begin
            ready <= 1'b1;
        end
    end

endmodule

// IDU 模块（修正mem_op赋值，统一为01:lw,10:lbu,11:sw,00:sb? 但根据funct3调整）
`timescale 1ns / 1ps
module idu (
    input wire clk,
    input wire rst,
    input wire [31:0] inst,
    input wire ifu_valid,
    output reg idu_ready,
    input wire exu_ready,

    input wire [31:0] inst_pc_from_ifu,

    output reg [4:0] rs1_addr,
    output reg [4:0] rs2_addr,
    output reg [4:0] rd_addr,
    output reg [31:0] imm,
    output reg [3:0] alu_op,
    output reg [1:0] mem_op,
    output reg reg_write,
    output reg jalr,
    output reg idu_valid,

    output reg [31:0] inst_pc_to_exu

);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            idu_ready <= 1'b1;
            idu_valid <= 1'b0;
            rs1_addr <= 5'h0;
            rs2_addr <= 5'h0;
            rd_addr <= 5'h0;
            imm <= 32'h0;
            alu_op <= 4'h0;
            mem_op <= 2'h0;
            reg_write <= 1'b0;
            jalr <= 1'b0;
            inst_pc_to_exu <= 32'h0;
        end else if (ifu_valid && exu_ready) begin
            idu_ready <= 1'b0;
            idu_valid <= 1'b1;

            inst_pc_to_exu <= inst_pc_from_ifu;

            rs1_addr <= inst[19:15];
            rs2_addr <= inst[24:20];
            rd_addr <= inst[11:7];

            case (inst[6:0])
                7'b0110011: begin // R-type: add
                    alu_op <= 4'h1; // ADD
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= 32'h0;
                end
                7'b0010011: begin // I-type: addi
                    alu_op <= 4'h1; // ADD
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= {{20{inst[31]}}, inst[31:20]};
                end
                7'b0110111: begin // U-type: lui
                    alu_op <= 4'h2; // LUI
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= {inst[31:12], 12'h0};
                end
                7'b0000011: begin // I-type: lw, lbu
                    alu_op <= 4'h1; // ADD for address
                    mem_op <= (inst[14:12] == 3'h2) ? 2'b01 :  // lw (funct3=2 -> 01)
                              (inst[14:12] == 3'h4) ? 2'b10 : 2'h0; // lbu (funct3=4 -> 10)
                    reg_write <= 1'b1;
                    jalr <= 1'b0;
                    imm <= {{20{inst[31]}}, inst[31:20]};
                end
                7'b0100011: begin // S-type: sw, sb
                    alu_op <= 4'h1; // ADD for address
                    mem_op <= (inst[14:12] == 3'h2) ? 2'b11 :  // sw (funct3=2 -> 11)
                              (inst[14:12] == 3'h0) ? 2'b00 : 2'h0; // sb (funct3=0 -> 00)
                    reg_write <= 1'b0;
                    jalr <= 1'b0;
                    imm <= {{20{inst[31]}}, inst[31:25], inst[11:7]};
                end
                7'b1100111: begin // I-type: jalr
                    alu_op <= 4'h1; // ADD for address
                    mem_op <= 2'h0;
                    reg_write <= 1'b1;
                    jalr <= 1'b1;
                    imm <= {{20{inst[31]}}, inst[31:20]};
                end
                default: begin
                    alu_op <= 4'h0;
                    mem_op <= 2'h0;
                    reg_write <= 1'b0;
                    jalr <= 1'b0;
                    imm <= 32'h0;
                end
            endcase
        end else begin
            idu_valid <= 1'b0;
            idu_ready <= 1'b1;
        end
    end
endmodule

// EXU 模块（新增lsu_rd_addr输出）
`timescale 1ns / 1ps
module exu (
    input wire clk,
    input wire rst,
    input wire [31:0] rs1_data,
    input wire [31:0] rs2_data,
    input wire [4:0] rd_addr,
    input wire [31:0] imm,
    input wire [3:0] alu_op,
    input wire [1:0] mem_op,
    input wire reg_write,
    input wire jalr,
    input wire idu_valid,

    input wire [31:0] inst_pc_from_idu,

    output reg exu_ready,
    output reg [31:0] lsu_addr,
    output reg [31:0] lsu_wdata,
    output reg [1:0] lsu_mem_op,
    output reg lsu_valid,
    input wire lsu_ready,
    output reg [4:0] lsu_rd_addr,  // 新增：传递rd_addr到LSU
    output reg [4:0] regfile_rd_addr,
    output reg [31:0] regfile_rd_data,
    output reg regfile_write,

    output reg jump_flag_from_exu,
    output reg [31:0] jump_addr_from_exu
);


    reg [31:0] alu_result;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            exu_ready <= 1'b1;
            lsu_valid <= 1'b0;
            regfile_write <= 1'b0;
            lsu_addr <= 32'h0;
            lsu_wdata <= 32'h0;
            lsu_mem_op <= 2'h0;
            lsu_rd_addr <= 5'h0;  // 新增重置
            regfile_rd_addr <= 5'h0;
            regfile_rd_data <= 32'h0;
            jump_addr_from_exu <= 32'b0;
            jump_flag_from_exu <= 1'b0;
        end else if (idu_valid && lsu_ready) begin
            exu_ready <= 1'b0;
            lsu_valid <= (mem_op != 2'h0);
            lsu_mem_op <= mem_op;
            lsu_wdata <= rs2_data;
            lsu_rd_addr <= rd_addr;  // 新增：传递到LSU
            regfile_rd_addr <= rd_addr;

                        
            alu_result <= (alu_op == 4'h1) ? (rs1_data + imm) : imm;

            if (jalr) begin
                jump_flag_from_exu <= 1'b1;
                jump_addr_from_exu <= alu_result & 32'hFFFFFFFE; 
            end else begin
                jump_flag_from_exu <= 1'b0;
                jump_addr_from_exu <= 32'h0;
            end
                        
            regfile_write <= reg_write && (mem_op == 2'h0);

            case (alu_op)
                4'h1: begin // ADD
                    lsu_addr <= alu_result;
                    if(jalr)begin
                       regfile_rd_data <= inst_pc_from_idu + 4; 
                    end else begin
                        regfile_rd_data <= alu_result;
                    end
                end
                4'h2: begin // LUI
                    regfile_rd_data <= imm;
                end
                default: begin
                    regfile_rd_data <= 32'h0;
                end
            endcase
        end else begin
            exu_ready <= 1'b1;
            lsu_valid <= 1'b0;
            regfile_write <= 1'b0;
            jump_flag_from_exu <= 1'b0; 
        end
    end
endmodule

// TOP 模块（无重大改动）
`timescale 1ns / 1ps

module ysyx_25040109_top (
    input wire clk,
    input wire rst,
    output wire [31:0] pc,
    output wire [31:0] inst,
    `ifndef SYNTHESIS
    input wire [31:0] p_count_number,
    `endif
    `ifdef SYNTHESIS
    input wire [31:0] yosys_store_load,
    `endif
    output wire [31:0] a0_out
);

    // IFU 访存接口
    wire [31:0] ifu_addr;
    wire [31:0] ifu_data;
    wire ifu_valid;
    wire ifu_ready;


    // LSU 访存接口
    wire [31:0] lsu_addr;
    wire [31:0] lsu_wdata;
    wire [31:0] lsu_rdata;
    wire [1:0] lsu_op;
    wire lsu_valid;
    wire lsu_ready;
    reg [31:0] inst_top;
    reg [31:0] ifu_idu_pc_top;
    reg [31:0] inst_pc_exu_top;

    // CPU 实例化
    minitv_cpu cpu (
        .inst_top(inst_top),
        .ifu_idu_pc_top(ifu_idu_pc_top),
        .inst_pc_exu_top(inst_pc_exu_top),
        .a0_out(a0_out),
        .clk(clk),
        .rst(rst),
        .ifu_addr(ifu_addr),
        .ifu_data(ifu_data),
        .ifu_valid(ifu_valid),
        .ifu_ready(ifu_ready),
        .lsu_addr(lsu_addr),
        .lsu_wdata(lsu_wdata),
        .lsu_rdata(lsu_rdata),
        .lsu_op(lsu_op),
        .lsu_valid(lsu_valid),
        .lsu_ready(lsu_ready)
    );

    // IFU 内存模块
    ifu_mem ifu_mem_inst (
        .clk(clk),
        .rst(rst),
        .addr(ifu_addr),
        .rdata(ifu_data),
        .valid(ifu_valid),
        .ready(ifu_ready)
    );

    // LSU 内存模块
    lsu_mem lsu_mem_inst (
        .clk(clk),
        .rst(rst),
        .addr(lsu_addr),
        .wdata(lsu_wdata),
        .rdata(lsu_rdata),
        .op(lsu_op),
        .lsu_valid(lsu_valid),
        .ready(lsu_ready)
    );

    // 输出连接
    assign pc = inst_pc_exu_top; // PC 从 IFU 的地址输出
    assign inst = inst_top; // 指令从 IFU 的数据输出


    // 仿真功能
    `ifndef SYNTHESIS
    import "DPI-C" function void update_decode_state(int pc, int snpc, int dnpc, int inst);
    import "DPI-C" function void itrace_print(int pc, int instruction_word, int instr_len_bytes, int p_count_number);
    import "DPI-C" function void printf_finish();

    wire [31:0] next_pc_internal = ifu_addr + 4; // 假设顺序执行，next_pc 近似为 pc + 4

    always @(*) begin
        update_decode_state(pc, pc + 32'd4, next_pc_internal, inst);
    end

    always @(posedge clk) begin
         $display("inst:0x%x   ifu_idu_pc_top:0x%08x    ",inst_top,ifu_idu_pc_top);
       // $display("inst:0x%x   ifu_idu_pc_top:0x%08x    inst_pc_exu_top:0x%08x    ",inst_top,ifu_idu_pc_top,inst_pc_exu_top);
        itrace_print(pc, inst, 4, p_count_number);

        if (inst_top == 32'h00100073) begin // ebreak 指令
            $display("enter finishi ,a0 decide ending\n");

           // $finish;
            printf_finish();
        end
    end
    `endif

endmodule

