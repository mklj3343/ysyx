module encorder(
    input en,
    input clk,
    input [7:0] D,
    output reg [2:0] out,
    output sympol
);

    always @(posedge clk) begin
        if(en) begin 
        out=3'b000;sympol=1'b0;
        end else begin
        casez(D)
        8'b1??????? : begin out=3'b111;sympol=1'b1;end
        8'b01?????? : begin out=3'b110;sympol=1'b1;end
        8'b001????? : begin out=3'b101;sympol=1'b1;end
        8'b0001???? : begin out=3'b100;sympol=1'b1;end
        8'b00001??? : begin out=3'b011;sympol=1'b1;end
        8'b000001?? : begin out=3'b010;sympol=1'b1;end
        8'b0000001? : begin out=3'b001;sympol=1'b1;end

        default:begin out=3'b000;sympol=1'b0;end
        endcase
    end    
end

endmodule
 
module seven_segment_display (
    input [2:0] num,
    output reg [6:0] seg
);

    always @(*)begin
        casez(num)
        3'd1:seg=7'b1001111;
        3'd2:seg=7'b0010010;
        3'd3:seg=7'b0000110;
        3'd4:seg=7'b1001100;
        3'd5:seg=7'b0100100;
        3'd6:seg=7'b1100000;
        3'd7:seg=7'b0001111;
        default:seg=7'b1111111;
        endcase
    end


endmodule



