module D_FF(Rst_1b, Set_1b, Q_1b, Clk);
	output reg  Q_1b;
	input Clk,Rst_1b, Set_1b;
	
	always @ (posedge Clk)
		if(Rst_1b)
			Q_1b<=1'b0;
		else if(Set_1b)	
			Q_1b=1'b1;
		else
			Q_1b<=Q_1b;
endmodule


module Mux2to1(Muxin0_2b, Muxin1_2b,Muxout_2b,Hit_1b);
	output reg [1:0] Muxout_2b;
	input [1:0] Muxin0_2b;
	input [1:0] Muxin1_2b;
	input Hit_1b;
	
	always @ (Muxin0_2b or Muxin1_2b or Hit_1b)
		case(Hit_1b)
			1'b0: Muxout_2b=Muxin0_2b;
			1'b1: Muxout_2b=Muxin1_2b;	
		endcase	
endmodule

module Decoder2to4(DecIn_2b,DecOut_4b);
	output reg [3:0] DecOut_4b;
	input [1:0] DecIn_2b;
	
	always @ (DecIn_2b)
		case(DecIn_2b)
			2'b00: DecOut_4b<=4'b0001;
			2'b01: DecOut_4b<=4'b0010;
			2'b10: DecOut_4b<=4'b0100;
			2'b11: DecOut_4b<=4'b1000;
		endcase
endmodule

module CacheMemory(Reset_1b,Memin_4b, Memout0_4b,Memout1_4b,Memout2_4b,Memout3_4b,Clk);
	output [3:0] Memout0_4b;
	output [3:0] Memout1_4b;
	output [3:0] Memout2_4b;
	output [3:0] Memout3_4b;
	input Reset_1b, Clk;
	input [3:0] Memin_4b;
	
	
	D_FF D00((Reset_1b|Memin_4b[0]), Memin_4b[0], Memout0_4b[3], Clk);
	D_FF D01((Reset_1b|Memin_4b[1]), Memin_4b[0], Memout0_4b[2], Clk);
	D_FF D02((Reset_1b|Memin_4b[2]), Memin_4b[0], Memout0_4b[1], Clk);
	D_FF D03((Reset_1b|Memin_4b[3]), Memin_4b[0], Memout0_4b[0], Clk);
	
	D_FF D10((Reset_1b|Memin_4b[0]), Memin_4b[1], Memout1_4b[3], Clk);
	D_FF D11((Reset_1b|Memin_4b[1]), Memin_4b[1], Memout1_4b[2], Clk);
	D_FF D12((Reset_1b|Memin_4b[2]), Memin_4b[1], Memout1_4b[1], Clk);
	D_FF D13((Reset_1b|Memin_4b[3]), Memin_4b[1], Memout1_4b[0], Clk);
	
	D_FF D20((Reset_1b|Memin_4b[0]), Memin_4b[2], Memout2_4b[3], Clk);
	D_FF D21((Reset_1b|Memin_4b[1]), Memin_4b[2], Memout2_4b[2], Clk);
	D_FF D22((Reset_1b|Memin_4b[2]), Memin_4b[2], Memout2_4b[1], Clk);
	D_FF D23((Reset_1b|Memin_4b[3]), Memin_4b[2], Memout2_4b[0], Clk);
	
	D_FF D30((Reset_1b|Memin_4b[0]), Memin_4b[3], Memout3_4b[3], Clk);
	D_FF D31((Reset_1b|Memin_4b[1]), Memin_4b[3], Memout3_4b[2], Clk);
	D_FF D32((Reset_1b|Memin_4b[2]), Memin_4b[3], Memout3_4b[1], Clk);
	D_FF D33((Reset_1b|Memin_4b[3]), Memin_4b[3], Memout3_4b[0], Clk);	

endmodule


module PrioEnco(Ein0_4b, Ein1_4b, Ein2_4b, Ein3_4b, Eout_2b);
	output reg [1:0] Eout_2b;
	input [3:0] Ein0_4b;
	input [3:0] Ein1_4b;
	input [3:0] Ein2_4b;
	input [3:0] Ein3_4b;
	
	always @ (Ein0_4b or Ein1_4b or Ein2_4b or Ein3_4b)
		begin 
			if(Ein0_4b==4'b0000)
				Eout_2b=2'b00;
			else if(Ein1_4b==4'b0000)	
				Eout_2b=2'b01;
			else if(Ein2_4b==4'b0000)	
				Eout_2b=2'b10;
			else
				Eout_2b=2'b11;
		end
endmodule

module LRU(Reset_1b,Hit_1b,Lineindex_2b,Nextindex_2b,Clk);
	output [1:0] Nextindex_2b;	
	input Reset_1b,Hit_1b, Clk;
	input [1:0] Lineindex_2b;
	wire [1:0] Muxout_2b;
	wire [3:0] DecOut_4b;
	wire [3:0] Memout0_4b;	
	wire [3:0] Memout1_4b;
	wire [3:0] Memout2_4b;
	wire [3:0] Memout3_4b;
	
	Mux2to1 M_LRU(Lineindex_2b, Nextindex_2b,Muxout_2b,Hit_1b);
	
	Decoder2to4 D_LRU(Muxout_2b,DecOut_4b);
	
	CacheMemory C_LRU(Reset_1b,DecOut_4b, Memout0_4b,Memout1_4b,Memout2_4b,Memout3_4b,Clk);

	PrioEnco P_LRU(Memout0_4b,Memout1_4b,Memout2_4b,Memout3_4b, Nextindex_2b);
endmodule


module tb();
	reg Reset_1b, Hit_1b, Clk;
	reg [1:0]	Lineindex_2b;
	wire [1:0] Nextindex_2b;

	LRU L(Reset_1b,Hit_1b,Lineindex_2b,Nextindex_2b,Clk);

	initial #200 $finish;
	
	initial begin Clk=0; forever #5 Clk=~Clk; end
	

	initial begin
			Reset_1b=1;	Hit_1b=0;	Lineindex_2b=2'b00;
	#12	Reset_1b=0;
	#10	Lineindex_2b=2'b01;
	#10	Lineindex_2b=2'b11;
	#10	Lineindex_2b=2'b10;
	#10	Hit_1b=1;
	end
endmodule
