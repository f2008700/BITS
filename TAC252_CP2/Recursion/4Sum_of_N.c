#include<stdio.h>


int sum(int n);

int main()

{
	int N;
	printf("Enter N\n");

	scanf("%d",&N);

	printf("Sum of %d is %d\n",N,sum(N));

	return 0;

}


int sum(int n)

{

	if(n<=0)

	{

		printf("N should be a positive integer\n");

		return 0;

	}

	else if(n==1)

		return 1;

	else

		return n+sum(n-1);

}
