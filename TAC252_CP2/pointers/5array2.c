#include<stdio.h>

void display1(int P[], int N);
void display2(int *P, int N);
void display3(int *P, int N);
 
int main()
{
	int A[]={22,33,44,55,11,23,34};
	int i,N=7;
	display1(A,N);
	display2(A,N);
	display3(A,N);
	return 0;
}

void display1(int P[], int N)
{
	int i;
	printf("From display1\n");
	for(i=0;i<N;i++)
		printf("%d\t",P[i]);
}

	
void display2(int *P, int N)
{
	int i;
	printf("\n\n\nFrom display2\n");
	for(i=0;i<N;i++)
		printf("%d\t",P[i]);
}


void display3(int *P, int N)
{
	int i;
	printf("\n\n\nFrom display3\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t",*(P+i));
	}
}
