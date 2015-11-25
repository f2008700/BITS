#include<stdio.h>

int main()
{
	int i,max,secmax,N=8;
	int A[]={10, 15, 12, 15, 30, 15, 30, 15};
	printf("The Array before the operation is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	if(A[0]>A[1])
	{
		max=A[0]; secmax=A[1];
	}
	else
	{
		max=A[1];secmax=A[0];
	}
	for(i=2;i<N;i++)
	{
		if(A[i]>max)
		{
			secmax=max; max=A[i];
		}
		else
		{
			if((A[i]>secmax)&&(A[i]!=max))
				secmax=A[i];
		}
	}
	printf("The Max is %d and the Second Max is %d\n",max,secmax);
	return 0;
}
