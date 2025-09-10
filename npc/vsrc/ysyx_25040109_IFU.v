module ysyx_25040109_IFU (

    input clk,
    input rst,

    input [31:0] next_pc,
    input pc_update_en,
    output [31:0]  pc_current,
    output [31:0] inst_out,
    output reg ifu_valid,

    output [31:0] ifu_raddr,
    input [31:0] ifu_rdata

);

    localparam STATE_IDLE = 1'b0 ;
    localparam STATE_WAIT = 1'b1 ;

    reg current_state;
    reg [31:0] inst_reg;

    ysyx_25040109_Reg #(.WIDTH(32),.RESET_VAL(32'h80000000)) pc_reg (
        .clk(clk),
        .rst(rst),
        .din(next_pc),
        .dout(pc_current),
        .wen(pc_update_en)
    );


    always @(posedge clk) begin
        if(rst)begin
            current_state <= STATE_IDLE;
        end else begin
            case(current_state)
                STATE_IDLE: current_state <= STATE_WAIT;
                STATE_WAIT: current_state <= STATE_IDLE;
            endcase
        end
    end


    assign ifu_raddr = pc_current;
    always @(posedge clk) begin
        if(!rst && current_state == STATE_WAIT)begin
            inst_reg <= ifu_rdata;
        end
    end

    assign inst_out = inst_reg;
    always @(*) begin
        ifu_valid = (current_state == STATE_WAIT);
    end




endmodule
