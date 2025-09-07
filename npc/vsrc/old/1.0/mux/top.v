module top(

    input clk,
    input  [1:0] Y,
    input  [1:0] X0,
    input  [1:0] X1,
    input  [1:0] X2,
    input  [1:0] X3,
    output reg [1:0] F
);

reg [1:0] change;

MuxKey #(4,2,2) i0 (
    .out(change),
    .key(Y),
    .lut({
        2'b00, X0,
        2'b01, X1,
        2'b10, X2,
        2'b11, X3
    })
);

always @(posedge clk)begin
    if(change==X0 & Y==2'b00) F=X0;
    if(change==X1 & Y==2'b01) F=X1;
    if(change==X2 & Y==2'b10) F=X2;
    if(change==X3 & Y==2'b11) F=X3;
end


endmodule

