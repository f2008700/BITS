module D_FF(in,out,Clk,WE);
	output reg out;
	input Clk,in,WE;
	
	always @ (posedge Clk)
		if(WE)
			out<=in;
		else	
			out<=out;
	
endmodule

module Mux32to1(in0,in1,in2,in3,in4,in5,in6,in7,in8,in9,in10,in11,in12,in13,in14,
in15,in16,in17,in18,in19,in20,in21,in22,in23,in24,in25,in26,in27,in28,in29,in30,in31,
out_Mux,select);

	output reg [31:0] out_Mux;
	//input en; 
	input [4:0] select;
	input [31:0] in0,in1,in2,in3,in4,in5,in6,in7,in8,in9,in10,in11,in12,in13,in14,in15,in16,in17,in18,in19,in20,in21,in22,in23,in24,in25,in26,in27,in28,in29,in30,in31;
	parameter s0=5'b00000,s1=5'b00001,s2=5'b00010,s3=5'b00011,s4=5'b00100,s5=5'b00101,
					s6=5'b00110,s7=5'b00111,s8=5'b01000,s9=5'b01001,s10=5'b01010,
					s11=5'b01011,s12=5'b01100,s13=5'b01101,s14=5'b01110,s15=5'b01111,
					s16=5'b10000,s17=5'b10001,s18=5'b10010,s19=5'b10011,s20=5'b10100,
					s21=5'b10101,s22=5'b10110,s23=5'b10111,s24=5'b11000,s25=5'b11001,
					s26=5'b11010,s27=5'b11011,s28=5'b11100,s29=5'b11101,s30=5'b11110,
					s31=5'b11111;
	
	always @(select or in0 or in1 or in2 or in3 or in4 or in5 or in6 or in7 or in8 or in9 or in10 or in11 or in12 or in13 or in14 or 
in15 or in16 or in17 or in18 or in19 or in20 or in21 or in22 or in23 or in24 or in25 or in26 or in27 or in28 or in29 or in30 or in31)
		case(select)
			s0:  out_Mux=in0;		s1:  out_Mux=in1;		s2:  out_Mux=in2;
			s3:  out_Mux=in3;		s4:  out_Mux=in4;		s5:  out_Mux=in5;
			s6:  out_Mux=in6;		s7:  out_Mux=in7;		s8:  out_Mux=in8;
			s9:  out_Mux=in9;		s10:  out_Mux=in10;		s11:  out_Mux=in11;
			s12:  out_Mux=in12;		s13:  out_Mux=in13;		s14:  out_Mux=in14;
			s15:  out_Mux=in15;		s16:  out_Mux=in16;		s17:  out_Mux=in17;
			s18:  out_Mux=in18;		s19:  out_Mux=in19;		s20:  out_Mux=in20;
			s21:  out_Mux=in21;		s22:  out_Mux=in22;		s23:  out_Mux=in23;
			s24:  out_Mux=in24;		s25:  out_Mux=in25;		s26:  out_Mux=in26;
			s27:  out_Mux=in27;		s28:  out_Mux=in28;		s29:  out_Mux=in29;
			s30:  out_Mux=in30;		s31:  out_Mux=in31;

		endcase
endmodule

module Decoder5to32(in_Dec, out_Dec);
	input [4:0]in_Dec;
	output reg[31:0]out_Dec;
	parameter s0=5'b00000,s1=5'b00001,s2=5'b00010,s3=5'b00011,s4=5'b00100,s5=5'b00101,s6=5'b00110,s7=5'b00111,s8=5'b01000,s9=5'b01001,s10=5'b01010,s11=5'b01011,s12=5'b01100,s13=5'b01101,s14=5'b01110,s15=5'b01111,s16=5'b10000,s17=5'b10001,s18=5'b10010,s19=5'b10011,s20=5'b10100,s21=5'b10101,s22=5'b10110,s23=5'b10111,s24=5'b11000,s25=5'b11001,s26=5'b11010,s27=5'b11011,s28=5'b11100,s29=5'b11101,s30=5'b11110,s31=5'b11111;

	always @(in_Dec)
		case(in_Dec)
			s0:  out_Dec=32'b00000000000000000000000000000001;
			s1:  out_Dec=32'b00000000000000000000000000000010;
			s2:  out_Dec=32'b00000000000000000000000000000100;
			s3:  out_Dec=32'b00000000000000000000000000001000;
			s4:  out_Dec=32'b00000000000000000000000000010000;
			s5:  out_Dec=32'b00000000000000000000000000100000;
			s6:  out_Dec=32'b00000000000000000000000001000000;
			s7:  out_Dec=32'b00000000000000000000000010000000;
			s8:  out_Dec=32'b00000000000000000000000100000000;
			s9:  out_Dec=32'b00000000000000000000001000000000;
			s10:  out_Dec=32'b00000000000000000000010000000000;
			s11:  out_Dec=32'b00000000000000000000100000000000;
			s12:  out_Dec=32'b00000000000000000001000000000000;
			s13:  out_Dec=32'b00000000000000000010000000000000;
			s14:  out_Dec=32'b00000000000000000100000000000000;
			s15:  out_Dec=32'b00000000000000001000000000000000;
			s16:  out_Dec=32'b00000000000000010000000000000000;
			s17:  out_Dec=32'b00000000000000100000000000000000;
			s18:  out_Dec=32'b00000000000001000000000000000000;
			s19:  out_Dec=32'b00000000000010000000000000000000;
			s20:  out_Dec=32'b00000000000100000000000000000000;
			s21:  out_Dec=32'b00000000001000000000000000000000;
			s22:  out_Dec=32'b00000000010000000000000000000000;
			s23:  out_Dec=32'b00000000100000000000000000000000;
			s24:  out_Dec=32'b00000001000000000000000000000000;
			s25:  out_Dec=32'b00000010000000000000000000000000;
			s26:  out_Dec=32'b00000100000000000000000000000000;
			s27:  out_Dec=32'b00001000000000000000000000000000;
			s28:  out_Dec=32'b00010000000000000000000000000000;
			s29:  out_Dec=32'b00100000000000000000000000000000;
			s30:  out_Dec=32'b01000000000000000000000000000000;
			s31:  out_Dec=32'b10000000000000000000000000000000;
	endcase
endmodule

module Register(in_Reg, out_Reg,Clk,Reg_Write);
	output [31:0] out_Reg;
	input Clk; input Reg_Write;
	input [31:0] in_Reg;
	
	D_FF D0(in_Reg[0],out_Reg[0],Clk,Reg_Write); 	D_FF D1(in_Reg[1],out_Reg[1],Clk,Reg_Write);
	D_FF D2(in_Reg[2],out_Reg[2],Clk,Reg_Write); 	D_FF D3(in_Reg[3],out_Reg[3],Clk,Reg_Write);
	D_FF D4(in_Reg[4],out_Reg[4],Clk,Reg_Write); 	D_FF D5(in_Reg[5],out_Reg[5],Clk,Reg_Write);
	D_FF D6(in_Reg[6],out_Reg[6],Clk,Reg_Write); 	D_FF D7(in_Reg[7],out_Reg[7],Clk,Reg_Write);
	D_FF D8(in_Reg[8],out_Reg[8],Clk,Reg_Write); 	D_FF D9(in_Reg[9],out_Reg[9],Clk,Reg_Write);
	D_FF D10(in_Reg[10],out_Reg[10],Clk,Reg_Write); D_FF D11(in_Reg[11],out_Reg[11],Clk,Reg_Write);
	D_FF D12(in_Reg[12],out_Reg[12],Clk,Reg_Write); D_FF D13(in_Reg[13],out_Reg[13],Clk,Reg_Write);
	D_FF D14(in_Reg[14],out_Reg[14],Clk,Reg_Write); D_FF D15(in_Reg[15],out_Reg[15],Clk,Reg_Write);
	D_FF D16(in_Reg[16],out_Reg[16],Clk,Reg_Write); D_FF D17(in_Reg[17],out_Reg[17],Clk,Reg_Write);
	D_FF D18(in_Reg[18],out_Reg[18],Clk,Reg_Write); D_FF D19(in_Reg[19],out_Reg[19],Clk,Reg_Write);
	D_FF D20(in_Reg[20],out_Reg[20],Clk,Reg_Write); D_FF D21(in_Reg[21],out_Reg[21],Clk,Reg_Write);
	D_FF D22(in_Reg[22],out_Reg[22],Clk,Reg_Write); D_FF D23(in_Reg[23],out_Reg[23],Clk,Reg_Write);
	D_FF D24(in_Reg[24],out_Reg[24],Clk,Reg_Write); D_FF D25(in_Reg[25],out_Reg[25],Clk,Reg_Write);
	D_FF D26(in_Reg[26],out_Reg[26],Clk,Reg_Write); D_FF D27(in_Reg[27],out_Reg[27],Clk,Reg_Write);
	D_FF D28(in_Reg[28],out_Reg[28],Clk,Reg_Write); D_FF D29(in_Reg[29],out_Reg[29],Clk,Reg_Write);
	D_FF D30(in_Reg[30],out_Reg[30],Clk,Reg_Write); D_FF D31(in_Reg[31],out_Reg[31],Clk,Reg_Write);
	
endmodule	

module RegFile(Rs,Rt,Rd,Data_In,Reg_Write,Bus_A,Bus_B,Clk);
	output [31:0] Bus_A,Bus_B;
	input [4:0] Rs,Rt,Rd;
	input Clk; input Reg_Write;
	input [31:0] Data_In;	
	wire [31:0]w0;	wire [31:0]w1;	wire [31:0]w2;
	wire [31:0]w3;	wire [31:0]w4;	wire [31:0]w5;	
	wire [31:0]w6;	wire [31:0]w7;	wire [31:0]w8;	
	wire [31:0]w9;	wire [31:0]w10;	wire [31:0]w11;	
	wire [31:0]w12;	wire [31:0]w13;	wire [31:0]w14;
	wire [31:0]w15;	wire [31:0]w16;	wire [31:0]w17;	
	wire [31:0]w18;	wire [31:0]w19;	wire [31:0]w20;	
	wire [31:0]w21;	wire [31:0]w22;	wire [31:0]w23; 
	wire [31:0]w24;	wire [31:0]w25; 	wire [31:0]w26; 
	wire [31:0]w27; 	wire [31:0]w28;	wire [31:0]w29; 
	wire [31:0]w30;	wire [31:0]w31; 	
	wire [31:0]d;
	wire [31:0]a;
	
	Decoder5to32 D0(Rd,d);
	and A0(a[0],Reg_Write,d[0]);	and A1(a[1],Reg_Write,d[1]);
	and A2(a[2],Reg_Write,d[2]);	and A3(a[3],Reg_Write,d[3]);	
	and A4(a[4],Reg_Write,d[4]);	and A5(a[5],Reg_Write,d[5]);
	and A6(a[6],Reg_Write,d[6]);	and A7(a[7],Reg_Write,d[7]);	
	and A8(a[8],Reg_Write,d[8]);	and A9(a[9],Reg_Write,d[9]);
	and A10(a[10],Reg_Write,d[10]);	and A11(a[11],Reg_Write,d[11]);	
	and A12(a[12],Reg_Write,d[12]);	and A13(a[13],Reg_Write,d[13]);
	and A14(a[14],Reg_Write,d[14]);	and A15(a[15],Reg_Write,d[15]);	
	and A16(a[16],Reg_Write,d[16]);	and A17(a[17],Reg_Write,d[17]);
	and A18(a[18],Reg_Write,d[18]);	and A19(a[19],Reg_Write,d[19]);	
	and A20(a[20],Reg_Write,d[20]);	and A21(a[21],Reg_Write,d[21]);
	and A22(a[22],Reg_Write,d[22]);	and A23(a[23],Reg_Write,d[23]);	
	and A24(a[24],Reg_Write,d[24]);	and A25(a[25],Reg_Write,d[25]);
	and A26(a[26],Reg_Write,d[26]);	and A27(a[27],Reg_Write,d[27]);	
	and A28(a[28],Reg_Write,d[28]);	and A29(a[29],Reg_Write,d[29]);
	and A30(a[30],Reg_Write,d[30]);	and A31(a[31],Reg_Write,d[31]);
	
	Register Rr0(Data_In, w0, Clk,a[0]); Register Rr1(Data_In, w1,Clk,a[1]);
	Register Rr2(Data_In, w2, Clk,a[2]); Register Rr3(Data_In, w3,Clk,a[3]);
	Register Rr4(Data_In, w4, Clk,a[4]); Register Rr5(Data_In, w5,Clk,a[5]);
	Register Rr6(Data_In, w6, Clk,a[6]); Register Rr7(Data_In, w7,Clk,a[7]);
	Register Rr8(Data_In, w8, Clk,a[8]); Register Rr9(Data_In, w9,Clk,a[9]);
	Register Rr10(Data_In, w10, Clk,a[10]); Register Rr11(Data_In, w11,Clk,a[11]);
	Register Rr12(Data_In, w12, Clk,a[12]); Register Rr13(Data_In, w13,Clk,a[13]);
	Register Rr14(Data_In, w14, Clk,a[14]); Register Rr15(Data_In, w15,Clk,a[15]);
	Register Rr16(Data_In, w16, Clk,a[16]); Register Rr17(Data_In, w17,Clk,a[17]);
	Register Rr18(Data_In, w18, Clk,a[18]); Register Rr19(Data_In, w19,Clk,a[19]);
	Register Rr20(Data_In, w20, Clk,a[20]); Register Rr21(Data_In, w21,Clk,a[21]);
	Register Rr22(Data_In, w22, Clk,a[22]); Register Rr23(Data_In, w23,Clk,a[23]);
	Register Rr24(Data_In, w24, Clk,a[24]); Register Rr25(Data_In, w25,Clk,a[25]);
	Register Rr26(Data_In, w26, Clk,a[26]); Register Rr27(Data_In, w27,Clk,a[27]);
	Register Rr28(Data_In, w28, Clk,a[28]); Register Rr29(Data_In, w29,Clk,a[29]);
	Register Rr30(Data_In, w30, Clk,a[30]); Register Rr31(Data_In, w31,Clk,a[31]);
	
	Mux32to1 M1(w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17,w18,w19,w20,
					w21,w22,w23,w24,w25,w26,w27,w28,w29,w30,w31,Bus_A,Rs);
	Mux32to1 M2(w0,w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12,w13,w14,w15,w16,w17,w18,w19,w20,
					w21,w22,w23,w24,w25,w26,w27,w28,w29,w30,w31,Bus_B,Rt);
endmodule	

module t_RegFile;
	wire	[31:0] Bus_A,Bus_B;			//output 
	reg 	[4:0] Rs,Rt,Rd;			//input
	reg	Clk; reg Reg_Write;		//input
	reg	[31:0] Data_In;			//input
	
	RegFile RF(Rs,Rt,Rd,Data_In,Reg_Write,Bus_A,Bus_B,Clk);
	
	initial #200 $finish; 
	
	initial begin Clk=0; forever #5 Clk=~Clk; end
	
	initial begin
	 Reg_Write=0; Rs=5'b00010; Rt=5'b00001; Rd=5'b00001;
		 Data_In=32'b00000000000000000000000000001110;
	#10 Reg_Write=1; 
	#20 Rd=5'b00010; Data_In=32'b00000000000000000000000000001100;

	end
endmodule
