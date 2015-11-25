/* 2:1 Multiplexer Program */

#include<stdio.h>

int mux(int input1, int input2, int select);

int main()
{
	int in1, in2, sel, out;
	printf("Enter Input1, Input 2 and Select\n");
	scanf("%d %d %d",&in1,&in2,&sel);
	if((sel==1)||(sel==0))
	{
		out=mux(in1,in2,sel);
		printf("The output is %d\n",out);
	}
	else
		printf("Wrong select Input\n");

	return 0;
}
int mux(int input1, int input2, int select)
{
	if(select==0)
		return input1;
	else
		return input2;
}
