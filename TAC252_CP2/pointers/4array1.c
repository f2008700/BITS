#include<stdio.h>

int main()
{
	int A[]={22,33,44,55,11,23,34};
	int i,N=7;
	int *p=A;

	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	
	printf("\n\n\n");
	

	for(i=0;i<N;i++)
		printf("%d\t",*(A+i));

	
	printf("\n\n\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",*(p+i));
	}
		printf("\n\n\n");

	for(i=0;i<N;i++)
	{
		printf("%d\t",(p[i]));
	}

	return 0;
}
