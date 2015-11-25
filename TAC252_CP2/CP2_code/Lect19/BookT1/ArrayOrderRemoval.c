#include<stdio.h>

int main()
{
	int i,temp,N=8;
	int A[]={10, 15, 20, 25, 30, 35, 44, 55};
	printf("The Array before Reversal is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	for(i=0;i<N/2;i++)
	{
		temp=A[i];
		A[i]=A[N-1-i];
		A[N-1-i]=temp;
	}
	printf("The Array after Reversal is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	return 0;
}
