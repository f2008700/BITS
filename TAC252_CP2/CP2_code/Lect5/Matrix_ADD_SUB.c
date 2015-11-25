/* Matrix Add / Sub */

#include<stdio.h>
#define N 10 

void MatAdd(int A[][N], int B[][N], int Res[][N], int size);
void MatSub(int A[][N], int B[][N], int Res[][N], int size);
void printMat(int A[][N], int size);

int main()
{
	int A[10][10], B[10][10], Sum[10][10], Sub[10][10];
	int i,j,size=5;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			A[i][j]=i+j;
			B[i][j]=i;
		}
	MatAdd(A,B,Sum,size);
	MatSub(A,B,Sub,size);
	
	printf("Matrix A\n");
	printMat(A,size);

	printf("Matrix B\n");
	printMat(B,size);

	printf("Matrix Sum\n");
	printMat(Sum,size);

	printf("Matrix Sub\n");
	printMat(Sub,size);
	
	return 0;
}

void MatAdd (int A[][N], int B[][N], int Res[][N], int size)
{
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			Res[i][j] = A[i][j] + B[i][j];
}

void MatSub (int A[][N], int B[][N], int Res[][N], int size)
{
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			Res[i][j] = A[i][j] - B[i][j];

}


void printMat (int A[][N], int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
}


