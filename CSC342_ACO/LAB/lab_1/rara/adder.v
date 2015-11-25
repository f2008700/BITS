`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:52:19 01/19/2012 
// Design Name: 
// Module Name:    adder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module adder(A,B,C,reset,sum,carry);
input [3:0] A;
input [3:0] B;
input C;
input reset;
output [3:0] sum;
output carry;
wire [3:0] A;
wire [3:0] B;
wire C;
wire reset;
wire [3:0] sum;
wire carry;

wire c0,c1,c2;

rara_v r1(.A (A[0]),.B (B[0]),.C (C),.reset (reset),.sum (sum[0]), .ca (c0));
rara_v r2(.A (A[1]),.B (B[1]),.C (c0),.reset (reset),.sum (sum[1]),.ca (c1));
rara_v r3(.A (A[2]),.B (B[2]),.C (c1),.reset (reset),.sum (sum[2]),.ca (c2));
rara_v r4(.A (A[3]),.B (B[3]),.C (c2),.reset (reset),.sum (sum[3]),.ca  (carry));
endmodule

module t_adder;

reg [3:0] t_A;
reg [3:0] t_B;
reg t_C;
reg t_reset;

wire [3:0] t_sum;
wire t_carry;
parameter stop = 50;

adder(t_A,t_B,t_C,t_reset,t_sum,t_carry);

initial #stop $finish;

initial 
	begin
	t_A =4'b0000; t_B=4'b0001; t_C=0; t_reset = 1;
	repeat(7)
	begin 
	#5 t_reset = 0;t_A= t_A + 4'b0001; t_B = t_B + 4'b0010;
	end
	#5 t_reset = 1;
	#5 t_reset = 0;
	end
	
initial
	begin
	$monitor("#%0d	%b	%b	%b	%b	%b	%b",$time,t_A,t_B,t_C,t_reset,t_carry,t_sum);
	end

endmodule 