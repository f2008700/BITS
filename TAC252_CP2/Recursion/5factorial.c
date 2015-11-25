#include<stdio.h>

int fact(int n);
int main()
{
	int N;
	printf("Enter N\n");
	scanf("%d",&N);
	printf("Fact of %d is %d\n",N,fact(N));
	return 0;
}

int fact(int n)
{
	if(n<0)
	{
		printf("N value should be Greater than or Equal to ZERO\n");
		return 0;
	}
	else if((n==0)||(n==1))
		return 1;
	else
		return n*fact(n-1);
}
