/* Function with arg and return value */

#include<stdio.h>

int Add(int, int);
int Sub(int, int);
int Mul(int, int);
float Div(int, int);

int main()
{
	int A,B;
	printf("Enter A and B\n");
	scanf("%d %d",&A,&B);

	printf("The Sum of %d and %d = %d\n",A,B,Add(A,B));
	printf("The Sub of %d and %d = %d\n",A,B,Sub(A,B));
	printf("The Mul of %d and %d = %d\n",A,B,Mul(A,B));
	printf("The Div of %d and %d = %f\n",A,B,Div(A,B));

	return 0;
}

int Add(int x, int y)
{
	return x+y;
}

int Sub(int x, int y)
{
	return x-y;
}


int Mul(int x, int y)
{
	return x*y;
}


float Div(int x, int y)
{
	if (y!=0)
		return (float)x/(float)y;
	else
		return 0;
}
