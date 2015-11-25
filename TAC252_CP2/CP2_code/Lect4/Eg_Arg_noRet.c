/* Function with no arg and no return value */

#include<stdio.h>

void displayline(char);
void sum(float, float);

int main()
{
	char ch;
	float A,B;
	printf("Enter A and B\n");
	scanf("%f %f ",&A,&B);
	printf("Enter the character\n");
	scanf("%c",&ch);
	displayline(ch);
	sum(A,B);
	return 0;
}
void displayline(char c)
{
	int i;
	for(i=0;i<40;i++)
		printf("%c",c);
	printf("\n");
}

void sum(float x, float y)
{
	printf("The Sum of %f and %f = %f\n",x,y,(x+y));
}

