#include<stdio.h>

int main()
{
	int A[10][5];
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<5;j++)
			A[i][j]=i*j;

printf("The Array is\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}

printf("\n\n By using Pointers\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
			printf("%d\t",*(*(A+i)+j));
		printf("\n");
	}
	A[2][3]=222;
	printf("%d\n",*(A[0]+2*5+3));
	return 0;
}
