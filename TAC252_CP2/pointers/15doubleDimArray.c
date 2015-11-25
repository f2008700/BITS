#include<stdio.h>
void display1(int P[][4],int row, int col);
void display2(int *P, int row, int col);
void display3(int **P, int row, int col);
void display4(int P[][4], int row, int col);
void display5(int (*P)[4], int row, int col);

int main()
{
	int A[3][4];
	int *P[3];
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			A[i][j]=i*j;

	for(i=0;i<3;i++)
		P[i]=A[i];
	display1(A,3,4);
	display2(A[0],3,4);
	display3(P,3,4);
	display4(A,3,4);
	display5(A,3,4);

	return 0;
}


void display1(int P[][4],int row, int col)
{
	int i,j;
	printf("the array starting address is %u\n",P);
	printf("From display 1 The Array is\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d\t",P[i][j]);
		printf("\n");
	}
}

void display2(int *P,int row, int col)
{
	int i,j;
	printf("From display 2 The Array is\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d\t",*(P+i*col+j));
		printf("\n");
	}
}

void display3 (int **P,int row, int col)
{
	int i,j;
	printf("From display 3 The Array is\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
	//		printf("%d\t",*(*(P+i)+j));
			printf("%d\t",P[i][j]);
			
		printf("\n");
	}
}

void display4(int P[][4],int row, int col)
{
	int i,j;
	printf("From display 4 The Array is\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d\t",*(*(P+i)+j));
		printf("\n");
	}
}

void display5(int (*P)[4],int row, int col)
{
	int i,j;
	int *q;
	printf("From display 5 The Array is\n");
	for(i=0;i<row;i++)
	{
		q=(int *)(P+i);
		for(j=0;j<col;j++)
			printf("%d\t",*(q+j));
		printf("\n");
	}
}
