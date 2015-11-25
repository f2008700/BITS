#include "compare.h"
int search(Element x, Element A[], int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(A[i]==x)
			return i;
		if(compare(A[i],x))
			return -1;
	}
	return -1;
}

