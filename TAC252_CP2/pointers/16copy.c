#include<stdio.h>
#include<stdlib.h>
#define MAXROWS 3
#define MAXCOLS 3

void copy1(int A[][MAXCOLS], int rows, int cols, int B[][MAXCOLS]);
int ** copy2(int A[][MAXCOLS], int rows, int cols);
void copy3(int A[][MAXCOLS], int rows, int cols, int ***B);

int main()
{
	int X[MAXROWS][MAXCOLS];
	int Y[MAXROWS][MAXCOLS];
	int i,j;
	int **Z;
	int **ret;
	for(i=0;i<MAXROWS;i++)
		for(j=0;j<MAXCOLS;j++)
			X[i][j]=i+j;	

	copy1(X,MAXROWS,MAXCOLS,Y);
	ret=copy2(X,MAXROWS,MAXCOLS);
	copy3(X,MAXROWS,MAXCOLS,&Z);
	printf("Output of copy1 --> Array Y\n");
	for(i=0;i<MAXROWS;i++)
	{
		for(j=0;j<MAXCOLS;j++)
		{
			printf("%d\t",Y[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");

	printf("Output of copy2 --> ret\n");
	for(i=0;i<MAXROWS;i++)
	{
		for(j=0;j<MAXCOLS;j++)
		{
			printf("%d\t",ret[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");

	printf("Output of copy3 --> Z\n");
	for(i=0;i<MAXROWS;i++)
	{
		for(j=0;j<MAXCOLS;j++)
		{
			printf("%d\t",Z[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");

	return 0;
}

void copy1(int A[][MAXCOLS], int M, int N, int B[][MAXCOLS])
{
	int i,j;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			B[i][j]=A[i][j];
}

int ** copy2(int A[][MAXCOLS], int M, int N)
{
	int i,j;
	int **B;

	B=(int **)malloc(M*sizeof(int *));
	for(i=0;i<M;i++)
		B[i]=(int *)malloc(N*sizeof(int));
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			B[i][j]=A[i][j];
		}
	}
	return B;
}

void copy3(int A[][MAXCOLS], int M, int N, int ***B)
{
	int i,j;
	*B=(int **)malloc(M*sizeof(int *));
	for(i=0;i<M;i++)
		(*B)[i]=(int *)malloc(N*sizeof(int));
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			(*B)[i][j]=A[i][j];
		}
	}
}

