/* Find Max from an Array */

#include<stdio.h>

int Max( int a[6], int N);

int main()
{
	int a[]={52,11,53,23,32,34};
	int N=6;
	printf("Starting address of A is %u, value of a = %u and address of a[0] = %u and value of a[0] = %d\n",&a,a,&a[0],a[0]);
//	printf("Address of a[2] = %u\n",&a[2]);
	printf("The Max element in Array A is %d\n",Max(a,N));
	return 0;
}

int Max (int x[6], int size)
{
//	printf("Starting address of x is %u, %u\n",&x,&x[0]);
	printf("Starting address of x is %u, value of x = %u and address of x[0] = %u and value of x[0] = %d\n",&x,x,&x[0],x[0]);
//	printf("Address of x[2] = %u\n",&x[2]);
	int i,M=x[0];
	for(i=1;i<size;i++)
		if(M<x[i])
			M=x[i];
	return M;
}
		
