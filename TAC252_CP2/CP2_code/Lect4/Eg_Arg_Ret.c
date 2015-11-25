/* Function with Arg and return value */

#include<stdio.h>

float sum(float, float);

int main()
{
	float A,B;
	printf("Enter A and B\n");
	scanf("%f %f",&A,&B);
	printf("The Sum of %f and %f = %f\n",A,B,sum(A,B));
	return 0;
}

float sum(float x, float y)
{
	return x+y;
}

