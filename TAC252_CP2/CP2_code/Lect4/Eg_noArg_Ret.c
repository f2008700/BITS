/* Function with No Arg but with return value */

#include<stdio.h>

float sum();

int main()
{
	printf("The Sum  = %f\n",sum());
	return 0;
}

float sum()
{
	float A,B;
	printf("Enter A and B\n");
	scanf("%f %f",&A,&B);
	return (A+B);
}

