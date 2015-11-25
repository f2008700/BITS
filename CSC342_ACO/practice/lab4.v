module D_FF(d_1b, q_1b, Write_1b, clk);
	input d_1b,Write_1b,clk;
	output reg q_1b;
	
	always @ (posedge clk)
		if(Write_1b)
				q_1b<=d_1b;
		else
				q_1b=q_1b;
endmodule

module Mux4to1(Din0_1b,Din1_1b, Din2_1b, Din3_1b, Dout_1b,Addr_2b );
	input Din0_1b,Din1_1b, Din2_1b, Din3_1b;
	input [1:0] Addr_2b;
	output reg Dout_1b;
	
	always @ (Din0_1b or Din1_1b or Din2_1b or Din3_1b or Addr_2b)
		case(Addr_2b)
			2'b00: Dout_1b<=Din0_1b;
			2'b01: Dout_1b<=Din1_1b;
			2'b10: Dout_1b<=Din2_1b;
			2'b11: Dout_1b<=Din3_1b;
		endcase
endmodule

module Mux2to1(Dout_3b, Zero_3b,Qout_3b,Read_1b);
	input [2:0] Dout_3b;
	input[2:0] Zero_3b;
	input Read_1b;
	output reg [2:0] Qout_3b;
		
	always @ (Dout_3b or Zero_3b or Read_1b)
		case(Read_1b)
			1'b0: Qout_3b<=Zero_3b;
			1'b1: Qout_3b<=Dout_3b;
		endcase
endmodule

module Decoder2to4(Addr_2b,Loc_4b);
	input [1:0] Addr_2b;
	output reg [3:0] Loc_4b;
	
	always @ (Addr_2b)
		case(Addr_2b)
			2'b00:	Loc_4b<=4'b0001;	
			2'b01:	Loc_4b<=4'b0010;
			2'b10:	Loc_4b<=4'b0100;
			2'b11:	Loc_4b<=4'b1000;
		endcase
endmodule

module Memory(Din_3b,Addr_2b,WE_1b,Read_1b,Qout_3b,clk);
	input [2:0] Din_3b;
	input [1:0] Addr_2b;
	input WE_1b, Read_1b, clk;
	output reg [2:0] Qout_3b;
	wire	w1,w2,w3,w4;
	wire [3:0] Loc_4b;
	wire	w00,w01,w02,w10,w11,w12,w20,w21,w22,w30,w31,w32;
	wire	[2:0] mux;
	parameter m6=3'b000;
		
	
	Decoder2to4 D1(Addr_2b,Loc_4b);
	and A1(w1,WE_1b,Loc_4b[0]);
	and A2(w2,WE_1b,Loc_4b[1]);
	and A3(w3,WE_1b,Loc_4b[2]);
	and A4(w4,WE_1b,Loc_4b[3]);
	
	D_FF D00(Din_3b[0], w00, w1, clk);
	D_FF D01(Din_3b[1], w01, w1, clk);
	D_FF D02(Din_3b[2], w02, w1, clk);
	
	D_FF D10(Din_3b[0], w10, w2, clk);
	D_FF D11(Din_3b[1], w11, w2, clk);
	D_FF D12(Din_3b[2], w12, w2, clk);
	
	D_FF D21(Din_3b[0], w20, w3, clk);
	D_FF D22(Din_3b[1], w21, w3, clk);
	D_FF D23(Din_3b[2], w22, w3, clk);
	
	D_FF D31(Din_3b[0], w30, w4, clk);
	D_FF D32(Din_3b[1], w31, w4, clk);
	D_FF D33(Din_3b[2], w32, w4, clk);
	
	Mux4to1 M1(w00,w10,w20,w30,mux[0],Addr_2b);
	Mux4to1 M2(w01,w11,w21,w31,mux[1],Addr_2b);
	Mux4to1 M3(w02,w12,w22,w32,mux[2],Addr_2b);
	
	
		
	Mux2to1 MM(mux, m6,Qout_3b,Read_1b);

endmodule	
	
module Memory_t;
	reg [2:0] Din_3b; 
	reg [1:0] Addr_2b;
	reg WE_1b, Read_1b, clk;
	wire [2:0] Qout_3b;
	
	Memory M(Din_3b,Addr_2b,WE_1b,Read_1b,Qout_3b,clk);
	
	initial #200 $finish;
	initial begin clk=0; forever #5 clk=~clk; end
	
	initial begin
		Din_3b=3'b000; Addr_2b=2'b00; WE_1b=1'b1; Read_1b=1'b1;

	#5	Din_3b=3'b000; Addr_2b=2'b00; WE_1b=1'b1; Read_1b=1'b1;
	#5	Din_3b=3'b010; Addr_2b=2'b01; WE_1b=1'b1; Read_1b=1'b1;
	#5	Din_3b=3'b011; Addr_2b=2'b00; WE_1b=1'b1; Read_1b=1'b1;
	#5	Din_3b=3'b110; Addr_2b=2'b00; WE_1b=1'b1; Read_1b=1'b1;
		
	#20 WE_1b = 1'b0;	
	#10 Read_1b = 1'b1;
	#20 Read_1b = 1'b0;
	//#20 Addr_2b = 2'b01;
	#20 Din_3b = 3'b111;	 
	#20 WE_1b = 1'b1;	
	#20 WE_1b = 1'b0;	
	#20 Read_1b = 1'b1;	
	end
endmodule
