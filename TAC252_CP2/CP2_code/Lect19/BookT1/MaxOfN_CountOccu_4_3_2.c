#include<stdio.h>

int main()
{
	int i,max,count,N=8;
	int A[]={10, 15, 12, 15, 30, 15, 30, 15};
	printf("The Array before the operation is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	max=A[0];count=1;
	for(i=1;i<N;i++)
	{
		if(A[i]>max)
		{
			max=A[i];
			count=1;
		}
		else
		{
			if(A[i]==max)
				count++;
		}
	}
	printf("The Max is %d and the occurence is %d\n",max,count);
	return 0;
}
