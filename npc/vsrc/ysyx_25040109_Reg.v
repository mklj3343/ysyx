module ysyx_25040109_Reg #(parameter WIDTH = 1,parameter RESET_VAL = 0) (
  input clk,
  input rst,
  input [WIDTH-1:0] din,
  output reg [WIDTH-1:0] dout,
  input wen
);
  always @(posedge clk ) begin
    if (rst)begin dout <= RESET_VAL;
    
    end  else if(wen)  begin
      dout <= din;
    end else begin
      dout <= dout;
    end
  end
endmodule



