/* Function with no arg and no return value */

#include<stdio.h>

void displayline();
void sum();

int main()
{
	displayline();
	sum();
	return 0;
}
void displayline()
{
	int i;
	for(i=0;i<40;i++)
		printf("_");
	printf("\n");
}

void sum()
{
	float A,B;
	printf("Enter A and B\n");
	scanf("%f %f",&A,&B);
	printf("The Sum of %f and %f = %f\n",A,B,(A+B));
}

