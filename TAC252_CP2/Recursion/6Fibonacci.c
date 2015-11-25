#include<stdio.h>


int fibIte(int n);

int fibRec(int n);

int main()

{

	int N;

	printf("Enter N\n");

	scanf("%d",&N);

	printf("Fibonacci (with Iteration) of %d is %d\n",N,fibIte(N));

	printf("Fibonacci (with Recursion) of %d is %d\n",N,fibRec(N));

	return 0;

}


int fibIte(int n)

{

	int f1,f2,f3,i;

	if(n<0)

	{

		printf("N value should be Greater than or Equal to ZERO\n");

		return 0;

	}

	else if((n==0)||(n==1))

		return n;

	else

	{

		f1=0;f2=1;f3=1;

		for(i=0;i<(n-2);i++)

		{

			f1=f2;

			f2=f3;

			f3=f1+f2;

		}

		return f3;

	}

}


int fibRec(int n)

{

	if(n<0)

	{

		printf("N value should be Greater than or Equal to ZERO\n");

		return 0;

	}

	else if((n==0)||(n==1))

		return n;

	else

		return (fibRec(n-2)+fibRec(n-1));

}
