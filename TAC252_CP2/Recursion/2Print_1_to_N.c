#include<stdio.h>

void print(int n);
int main()
{
	int N;
	printf("Enter N\n");
	scanf("%d",&N);
	print(N);
	return 0;
}

void print(int n)
{
	if (n<0)
		printf("N should be a Positive Integer\n");
	else if(n==0)
		return;
	else
	{
		print(n-1);
		printf("%d\t",n);
	}
}
