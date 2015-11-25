#include<stdio.h>

int mul(int n, int m);

int main()

{

	int res,N,M;

	printf("Enter N and M\n");

	scanf("%d %d",&N,&M);

	res=mul(N,M);

	printf("The %d * %d = %d\n",N,M,res);

	return 0;

}


int mul(int n, int m)

{

	if(m<=0)

	{

		printf("M should be positive\n");

		return 0;

	}

	else if(m==1)

		return n;

	else

		return (n+mul(n,(m-1)));

}
