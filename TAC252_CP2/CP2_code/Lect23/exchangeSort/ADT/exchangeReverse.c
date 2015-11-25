/* file name: selection.c */

#include "compare.h"

void exchangesort(List A, int N)
{
	int i,j,temp;
	i=0;
	for(i=0;i<N-1;i++)
	{
		for(j=(i+1);j<N;j++)
		{
			if(compare(A[j],A[i]))
			{
				temp=A[j];
				A[j]=A[i];
				A[i]=temp;
			}
		}
	}
}
