module ysyx_25040109_IDU (
    input  [31:0] inst,
    output [4:0]  rd_addr,
    output [4:0]  rs1_addr,
    output [4:0]  rs2_addr,
    output [31:0] imm,
    output        reg_write_en_idu,
    output [2:0]  funct3,
    output [6:0]  funct7,
    output        inst_invalid,
    output [11:0] csr_addr
);
    wire [6:0] opcode = inst[6:0];
    assign funct3  = inst[14:12];
    assign funct7  = inst[31:25];
    assign rd_addr = inst[11:7];
    assign rs1_addr = inst[19:15];
    assign rs2_addr = inst[24:20];

    wire [11:0] imm_i = inst[31:20];
    wire [19:0] imm_u = inst[31:12];
    wire [20:1] imm_j = {inst[31], inst[19:12], inst[20], inst[30:21]};
    wire [11:0] imm_s = {inst[31:25], inst[11:7]};
    wire [12:1] imm_b = {inst[31], inst[7], inst[30:25], inst[11:8]};

    wire [31:0] imm_i_ext = {{20{imm_i[11]}}, imm_i};
    wire [31:0] imm_u_ext = {imm_u, 12'b0};
    wire [31:0] imm_j_ext = {{11{imm_j[20]}}, imm_j, 1'b0};
    wire [31:0] imm_s_ext = {{20{imm_s[11]}}, imm_s};
    wire [31:0] imm_b_ext = {{19{imm_b[12]}}, imm_b, 1'b0};

    ysyx_25040109_MuxKeyWithDefault #(8, 7, 32) imm_select (
        .out(imm),
        .key(opcode),
        .default_out(32'b0),
        .lut({
            7'b0010111, imm_u_ext,
            7'b0110111, imm_u_ext,
            7'b0010011, imm_i_ext,
            7'b0000011, imm_i_ext,
            7'b1100111, imm_i_ext,
            7'b0100011, imm_s_ext,
            7'b1101111, imm_j_ext,
            7'b1100011, imm_b_ext
        })
    );

    assign reg_write_en_idu = (opcode == 7'b0110111) ||
                              (opcode == 7'b0010111) ||
                              (opcode == 7'b1101111) ||
                              (opcode == 7'b1100111) ||
                              (opcode == 7'b0000011) ||
                              (opcode == 7'b0010011) ||
                              (opcode == 7'b0110011) ||
                              (opcode == 7'b1110011);

    wire valid_lui    = (opcode == 7'b0110111);
    wire valid_auipc  = (opcode == 7'b0010111);
    wire valid_jal    = (opcode == 7'b1101111);
    wire valid_jalr   = (opcode == 7'b1100111) && (funct3 == 3'b000);

    wire valid_load = (opcode == 7'b0000011) && (
        funct3 == 3'b000 ||
        funct3 == 3'b001 ||
        funct3 == 3'b010 ||
        funct3 == 3'b100 ||
        funct3 == 3'b101
    );

    wire valid_store = (opcode == 7'b0100011) && (
        funct3 == 3'b000 ||
        funct3 == 3'b001 ||
        funct3 == 3'b010
    );

    wire valid_branch = (opcode == 7'b1100011) && (
        funct3 == 3'b000 ||
        funct3 == 3'b001 ||
        funct3 == 3'b101 ||
        funct3 == 3'b100 ||
        funct3 == 3'b110 ||
        funct3 == 3'b111
    );

    wire valid_i_type = (opcode == 7'b0010011) && (
        funct3 == 3'b000 ||
        funct3 == 3'b010 ||
        funct3 == 3'b011 ||
        funct3 == 3'b100 ||
        funct3 == 3'b110 ||
        funct3 == 3'b111 ||
        (funct3 == 3'b001 && funct7 == 7'b0000000) ||
        (funct3 == 3'b101 && funct7 == 7'b0000000) ||
        (funct3 == 3'b101 && funct7 == 7'b0100000)
    );

    wire valid_r_type = (opcode == 7'b0110011) && (
        (funct3 == 3'b000 && funct7 == 7'b0000000) ||
        (funct3 == 3'b000 && funct7 == 7'b0100000) ||
        (funct3 == 3'b001 && funct7 == 7'b0000000) ||
        (funct3 == 3'b010 && funct7 == 7'b0000000) ||
        (funct3 == 3'b011 && funct7 == 7'b0000000) ||
        (funct3 == 3'b100 && funct7 == 7'b0000000) ||
        (funct3 == 3'b101 && funct7 == 7'b0000000) ||
        (funct3 == 3'b101 && funct7 == 7'b0100000) ||
        (funct3 == 3'b110 && funct7 == 7'b0000000) ||
        (funct3 == 3'b111 && funct7 == 7'b0000000) ||
        (funct3 == 3'b000 && funct7 == 7'b0000001) ||
        (funct3 == 3'b001 && funct7 == 7'b0000001) ||
        (funct3 == 3'b100 && funct7 == 7'b0000001) ||
        (funct3 == 3'b101 && funct7 == 7'b0000001) ||
        (funct3 == 3'b110 && funct7 == 7'b0000001) ||
        (funct3 == 3'b111 && funct7 == 7'b0000001)
    );

    wire is_system_op = (opcode == 7'b1110011);
    wire [11:0] funct12 = inst[31:20];

    wire valid_system = is_system_op && (
        (funct3 == 3'b000 && funct12 == 12'h000) ||
        (funct3 == 3'b000 && funct12 == 12'h001) ||
        (funct3 == 3'b000 && funct12 == 12'h302) ||
        (funct3 == 3'b001) ||
        (funct3 == 3'b010)
    );

    assign csr_addr = valid_system ? inst[31:20] : 12'h0;

    assign inst_invalid = ~(valid_lui || valid_auipc || valid_jal || valid_jalr ||
                             valid_load || valid_store || valid_branch ||
                             valid_i_type || valid_r_type || valid_system);
endmodule
