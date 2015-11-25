#include<stdio.h>

int main()
{
	int i,j,k,temp,N=8;
	int A[]={10, 15, 20, 25, 30, 35, 44, 55};
	printf("The Array before Reversal is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	j=0;
	for(i=1;i<N;i=i+2)
	{
		temp=A[i];
		for(k=i;k>j;k--)
		{
			A[k]=A[k-1];
		}
		A[j]=temp;
		j++;
	}
	printf("The Array after Reversal is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	return 0;
}
