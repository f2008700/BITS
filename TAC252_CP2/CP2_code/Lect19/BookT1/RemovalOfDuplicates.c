#include<stdio.h>

int main()
{
	int i,j,N=8;
	int A[]={10, 15, 15, 15, 30, 30, 45, 45};
	printf("The Array before the operation is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	i=1;
	while(A[i-1]!=A[i]) i++;
	j=i;
	for(;i<N;i++)
	{
		if(A[i]!=A[i-1])
		{
			A[j]=A[i];j++;
		}
	}
	N=j;
	
	printf("The Array After the operation is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	return 0;
}
