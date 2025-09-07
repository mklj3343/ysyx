module top(
    input clk,
    input rst,
    output reg [15:0] led
);
  light u_kdlight(
    .clk(clk),
    .rst(rst),
    .led(led)
  );

    endmodule
