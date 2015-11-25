#include "compare.h"

void selectionsort(List A, int N)
{
	int i,j,pmin,pmax;
	Member min,max;
	for(i=0;i<(N-1);i++)
	{
		min=A[i];
		max=A[i];
		pmin=i;
		pmax=i;
		for(j=i+1;j<N;j++)
		{
			if(A[j]<min)
			{
				min=A[j];
				pmin=j;
			}
			else
			{
				if(A[j]>max)
				{
					max=A[j];
					pmax=j;
				}
			}
		}
		
		A[pmin]=A[i];
		A[i]=min;
		if(pmax==i)
			pmax=pmin;
		A[pmax]=A[(N-1)];
		A[(N-1)]=max;
		N--;
	}
}
