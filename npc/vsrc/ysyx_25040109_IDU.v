// Instruction Decode Unit (IDU)
// 功能：指令译码
// - 解析指令字段（opcode, funct3, funct7, rd, rs1, rs2）
// - 生成立即数
// - 生成控制信号
// - 指令有效性检查
// - CSR地址提取
module ysyx_25040109_IDU (
    input [31:0] inst,
    output [4:0] rd_addr,
    output [31:0] imm,
    output reg_write_en_idu,
    output [2:0] funct3,
    output [6:0] funct7,
    output reg inst_invalid,
    output [11:0] csr_addr,
    output [6:0] opcode
);
    // 指令字段解析
    assign opcode = inst[6:0];
    assign funct3 = inst[14:12];
    assign funct7 = inst[31:25];
    assign rd_addr = inst[11:7];
    
    // 立即数字段提取
    wire [11:0] imm_i = inst[31:20];
    wire [19:0] imm_u = inst[31:12];
    wire [20:1] imm_j = {inst[31], inst[19:12], inst[20], inst[30:21]};
    wire [11:0] imm_s = {inst[31:25], inst[11:7]};
    wire [12:1] imm_b = {inst[31], inst[7], inst[30:25], inst[11:8]};

    // 立即数符号扩展
    wire [31:0] imm_i_ext = {{20{imm_i[11]}}, imm_i};
    wire [31:0] imm_u_ext = {imm_u, 12'b0};
    wire [31:0] imm_j_ext = {{11{imm_j[20]}}, imm_j, 1'b0};
    wire [31:0] imm_s_ext = {{20{imm_s[11]}}, imm_s};
    wire [31:0] imm_b_ext = {{19{imm_b[12]}}, imm_b, 1'b0};

    // 立即数选择
    ysyx_25040109_MuxKeyWithDefault #(8, 7, 32) imm_select (
        .out(imm),
        .key(opcode),
        .default_out(32'b0), 
        .lut({
            7'b0010111, imm_u_ext,  // AUIPC
            7'b0110111, imm_u_ext,  // LUI
            7'b0010011, imm_i_ext,  // I-type ALU
            7'b0000011, imm_i_ext,  // Load
            7'b1100111, imm_i_ext,  // JALR
            7'b0100011, imm_s_ext,  // Store
            7'b1101111, imm_j_ext,  // JAL
            7'b1100011, imm_b_ext   // Branch
        })
    );

    // 寄存器写使能
    assign reg_write_en_idu = (opcode == 7'b0110111) ||  // LUI
                              (opcode == 7'b0010111) ||  // AUIPC
                              (opcode == 7'b1101111) ||  // JAL
                              (opcode == 7'b1100111) ||  // JALR
                              (opcode == 7'b0000011) ||  // Load
                              (opcode == 7'b0010011) ||  // I-type ALU
                              (opcode == 7'b0110011) ||  // R-type
                              (opcode == 7'b1110011);    // System (CSR)
                              
    // 指令有效性验证
    wire valid_lui    = (opcode == 7'b0110111);
    wire valid_auipc  = (opcode == 7'b0010111);
    wire valid_jal    = (opcode == 7'b1101111);
    wire valid_jalr   = (opcode == 7'b1100111) && (funct3 == 3'b000);

    wire valid_load = (opcode == 7'b0000011) && (
        funct3 == 3'b000 ||  // LB
        funct3 == 3'b001 ||  // LH
        funct3 == 3'b010 ||  // LW
        funct3 == 3'b100 ||  // LBU
        funct3 == 3'b101     // LHU
    );

    wire valid_store = (opcode == 7'b0100011) && (
        funct3 == 3'b000 ||  // SB
        funct3 == 3'b001 ||  // SH
        funct3 == 3'b010     // SW
    );

    wire valid_branch = (opcode == 7'b1100011) && (
        funct3 == 3'b000 ||  // BEQ
        funct3 == 3'b001 ||  // BNE
        funct3 == 3'b100 ||  // BLT
        funct3 == 3'b101 ||  // BGE
        funct3 == 3'b110 ||  // BLTU
        funct3 == 3'b111     // BGEU
    );

    wire valid_i_type = (opcode == 7'b0010011) && (
        funct3 == 3'b000 ||  // ADDI
        funct3 == 3'b010 ||  // SLTI
        funct3 == 3'b011 ||  // SLTIU
        funct3 == 3'b100 ||  // XORI
        funct3 == 3'b110 ||  // ORI
        funct3 == 3'b111 ||  // ANDI
        (funct3 == 3'b001 && funct7 == 7'b0000000) ||  // SLLI
        (funct3 == 3'b101 && funct7 == 7'b0000000) ||  // SRLI
        (funct3 == 3'b101 && funct7 == 7'b0100000)     // SRAI
    );

    wire valid_r_type = (opcode == 7'b0110011) && (
        (funct3 == 3'b000 && funct7 == 7'b0000000) ||  // ADD
        (funct3 == 3'b000 && funct7 == 7'b0100000) ||  // SUB
        (funct3 == 3'b001 && funct7 == 7'b0000000) ||  // SLL
        (funct3 == 3'b010 && funct7 == 7'b0000000) ||  // SLT
        (funct3 == 3'b011 && funct7 == 7'b0000000) ||  // SLTU
        (funct3 == 3'b100 && funct7 == 7'b0000000) ||  // XOR
        (funct3 == 3'b101 && funct7 == 7'b0000000) ||  // SRL
        (funct3 == 3'b101 && funct7 == 7'b0100000) ||  // SRA
        (funct3 == 3'b110 && funct7 == 7'b0000000) ||  // OR
        (funct3 == 3'b111 && funct7 == 7'b0000000) ||  // AND
        // M扩展指令
        (funct3 == 3'b000 && funct7 == 7'b0000001) ||  // MUL
        (funct3 == 3'b001 && funct7 == 7'b0000001) ||  // MULH
        (funct3 == 3'b100 && funct7 == 7'b0000001) ||  // DIV
        (funct3 == 3'b101 && funct7 == 7'b0000001) ||  // DIVU
        (funct3 == 3'b110 && funct7 == 7'b0000001) ||  // REM
        (funct3 == 3'b111 && funct7 == 7'b0000001)     // REMU
    );

    wire is_system_op = (opcode == 7'b1110011);
    wire [11:0] funct12 = inst[31:20];

    wire valid_system = is_system_op && (
        (funct3 == 3'b000 && funct12 == 12'h000) ||  // ECALL
        (funct3 == 3'b000 && funct12 == 12'h001) ||  // EBREAK
        (funct3 == 3'b000 && funct12 == 12'h302) ||  // MRET
        (funct3 == 3'b001) ||                        // CSRRW
        (funct3 == 3'b010)                           // CSRRS
    );            

    // CSR地址提取
    assign csr_addr = valid_system ? inst[31:20] : 12'h0;

    // 指令无效判断
    always @(*) begin
        if (valid_lui || valid_auipc || valid_jal || valid_jalr ||
            valid_load || valid_store || valid_branch || 
            valid_i_type || valid_r_type || valid_system) begin
            inst_invalid = 1'b0;
        end else begin
            inst_invalid = 1'b1;
            `ifndef SYNTHESIS
            $display("Invalid instruction: 0x%08x", inst);
            `endif
        end
    end

endmodule
