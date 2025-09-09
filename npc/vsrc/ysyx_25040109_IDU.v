module ysyx_25040109_IDU (
    input  [31:0] inst,
    output [4:0]  rd_addr,
    output [31:0] imm,
    output        is_load,
    output        is_store,
    output        reg_write_en,
    output [2:0]  funct3,
    output        inst_invalid,

    output        is_add,
    output        is_lui,
    output        is_jalr,
    output        is_csrrw,
    output [11:0] csr_addr
);
  wire [6:0] opcode = inst[6:0];
    assign funct3     = inst[14:12];
    assign rd_addr    = inst[11:7];
    
    assign csr_addr = inst[31:20];

    assign is_lui = (opcode == 7'b0110111);
    wire is_addi = (opcode == 7'b0010011) && (funct3 == 3'b000);
    assign is_add = (opcode == 7'b0110011) && (funct3 == 3'b000) && (inst[31:25] == 7'b0000000);
    assign is_jalr = (opcode == 7'b1100111) && (funct3 == 3'b000);
    assign is_load = (opcode == 7'b0000011) && (funct3 == 3'b010 || funct3 == 3'b100);  // lw/lbu
    assign is_store = (opcode == 7'b0100011) && (funct3 == 3'b010 || funct3 == 3'b000);
    assign is_csrrw = (opcode == 7'b1110011) && (funct3 == 3'b001 || funct3 == 3'b010);



    wire [19:0] imm_u = inst[31:12];
    wire [11:0] imm_i = inst[31:20];
    wire [11:0] imm_s = {inst[31:25], inst[11:7]};

    wire [31:0] imm_u_ext = {imm_u, 12'b0};
    wire [31:0] imm_i_ext = {{20{imm_i[11]}}, imm_i};
    wire [31:0] imm_s_ext = {{20{imm_s[11]}}, imm_s};

    assign imm = is_lui            ? imm_u_ext :
                 (is_store)        ? imm_s_ext :
                                     imm_i_ext;

assign reg_write_en = is_lui || is_addi || is_add || is_jalr || is_load || is_csrrw;

assign inst_invalid = !(is_lui || is_addi || is_add || is_jalr || is_load || is_store  || is_csrrw);



endmodule
