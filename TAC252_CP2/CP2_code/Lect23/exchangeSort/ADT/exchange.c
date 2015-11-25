/* file name: selection.c */

#include "compare.h"

void exchangesort(List A, int N)
{
	int i,j,temp,sorted;
	i=0; sorted=0;
	while((i<N-1) && (sorted==0))
	{
		j=0;
		sorted=1;
		while(j<(N-i-1))
		{
			if(compare(A[j+1],A[j]))
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				sorted=0;
			}
			j++;
		}
		i++;
	}
}
