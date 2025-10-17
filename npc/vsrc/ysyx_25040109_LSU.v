// Load-Store Unit (LSU)
// 负责所有访存操作：Load和Store
module ysyx_25040109_LSU (
    input clk,
    input rst,

    // 来自EXU的地址和控制信号
    input [31:0] mem_addr,
    input [31:0] store_data,
    input [2:0]  funct3,
    input [6:0]  opcode,
    input        inst_invalid,

    // Load结果输出
    output reg [31:0] load_result,

    `ifdef SYNTHESIS
    input  [31:0] yosys_load_data,
    `endif

    output wire is_load,
    output wire is_store
);

    // 识别Load和Store指令
    assign is_load  = (opcode == 7'b0000011) && !inst_invalid;
    assign is_store = (opcode == 7'b0100011) && !inst_invalid;

    `ifndef SYNTHESIS
    // DPI-C函数声明
    import "DPI-C" function void verilog_pmem_read(input int addr, output int data);
    import "DPI-C" function void verilog_pmem_write(input int addr, input int data, input int len);
    `endif

    reg [31:0] mem_data_raw;

    // Load操作：读取内存并进行数据扩展
    always @(*) begin
        if (is_load) begin
            `ifndef SYNTHESIS
            verilog_pmem_read(mem_addr, mem_data_raw);
            `else
            mem_data_raw = yosys_load_data;
            `endif

            case (funct3)
                3'b000: load_result = {{24{mem_data_raw[7]}},  mem_data_raw[7:0]};   // LB
                3'b001: load_result = {{16{mem_data_raw[15]}}, mem_data_raw[15:0]}; // LH
                3'b010: load_result = mem_data_raw;                                  // LW
                3'b100: load_result = {24'b0, mem_data_raw[7:0]};                   // LBU
                3'b101: load_result = {16'b0, mem_data_raw[15:0]};                  // LHU
                default: load_result = 32'b0;
            endcase
        end else begin
            mem_data_raw = 32'h0;
            load_result  = 32'b0;
        end
    end

    // Store操作：写入内存（仿真环境）
    `ifndef SYNTHESIS
    always @(posedge clk) begin
        if (!rst && is_store) begin
            case (funct3)
                3'b000: verilog_pmem_write(mem_addr, store_data, 1); // SB
                3'b001: verilog_pmem_write(mem_addr, store_data, 2); // SH
                3'b010: verilog_pmem_write(mem_addr, store_data, 4); // SW
                default: ;
            endcase
        end
    end
    `endif

endmodule
