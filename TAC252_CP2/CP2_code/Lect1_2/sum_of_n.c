/* Sum of N numbers */
#include<stdio.h>

int main()
{
	int N,i,sum;
	printf("Enter N\n");
	scanf("%d",&N);
	if(N>0)
	{
		sum = 1; /* Atomic Solution */
		for(i=2;i<=N;i++)
			sum = sum + i;
		printf("The Sum = %d\n",sum);
	}
	else
		printf("Wrong N\n");

	return 0;
}
