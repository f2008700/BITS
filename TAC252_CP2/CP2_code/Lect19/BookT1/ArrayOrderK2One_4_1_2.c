#include<stdio.h>

int main()
{
	int i,j,k,temp,N=8;
	k=5;
	int A[]={10, 15, 20, 25, 30, 35, 44, 55};
	printf("The Array before Rearrange is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	for(i=0;i<k;i++)
	{
		temp=A[0];
		for(j=0;j<(N-1);j++)
			A[j]=A[j+1];
		A[N-1]=temp;
	}
	printf("The Array after Rearrange is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	return 0;
}
