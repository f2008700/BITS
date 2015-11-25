/* file name: selection.c */

#include "compare.h"
void selectionsort(List A, int N)
{
	int i,j,p;
	Member min;
	for(i=0;i<(N-1);i++)
	{
		min=A[i];
		p=i;
		for(j=i+1;j<N;j++)
		{
			if(compare(A[j],min))
			{
				min=A[j];
				p=j;
			}
		}
		A[p]=A[i];
		A[i]=min;
	}
}
