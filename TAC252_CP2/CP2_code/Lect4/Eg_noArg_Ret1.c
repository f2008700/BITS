/* Function with No Arg but with return value */

#include<stdio.h>

int ReadNumber(void);

int main()
{
	int num=ReadNumber();
	printf("The Number  = %d\n",num);
	return 0;
}

int ReadNumber()
{
	int N;
	printf("Enter the Number\n");
	scanf("%d",&N);
	return N;
}

