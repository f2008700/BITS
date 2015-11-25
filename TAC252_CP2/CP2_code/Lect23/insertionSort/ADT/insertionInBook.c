/* file name: selection.c */

#include "compare.h"

void insertionsort(List A, int N)
{
	int i,j,min,pos,x;
	min=A[0];pos=0;
	for(i=1;i<N;i++)
	{
		if(A[i]<min)
		{
			min=A[i];
			pos=i;
		}
	}
	A[pos]=A[0];
	A[0]=min;

	for(i=2;i<N;i++)
	{
		x=A[i];
		j=i;
		while(x<A[j-1])
		{
			A[j]=A[j-1];
			j--;
		}
		A[j]=x;
	}
}
