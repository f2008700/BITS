#include<stdio.h>
#include<stdlib.h>

void copy1(int *A, int N, int *B);
int * copy2(int *A, int N);
void copy3(int *A, int N, int **B);

int main()
{
	int X[]={1,2,3,4,5,6,7};
	int i,size=7;
	int Y[7];
	int *Z;
	int *ret;

	copy1(X,size,Y);
	ret=copy2(X,size);
	copy3(X,size,&Z);
	printf("Output of copy1 --> Array Y\n");
	for(i=0;i<size;i++)
		printf("%d\t",Y[i]);
	printf("\n\n\n");

	printf("Output of copy2 --> ret\n");
	for(i=0;i<size;i++)
		printf("%d\t",ret[i]);
	printf("\n\n\n");

	printf("Output of copy3 --> Z\n");
	for(i=0;i<size;i++)
		printf("%d\t",Z[i]);
	printf("\n\n\n");


	return 0;
}

void copy1(int *A, int N, int *B)
{
	int i;
	for(i=0;i<N;i++)
		B[i]=A[i];
}

int * copy2(int *A, int N)
{
	int i;
	int *B=(int *)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
		B[i]=A[i];
	return B;
}

void copy3(int *A, int N, int **B)
{
	int i;
	*B=(int *)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
		(*B)[i]=A[i];
}

