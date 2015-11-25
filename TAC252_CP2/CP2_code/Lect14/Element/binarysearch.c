/* File Name: orderedsearch.c
 * implementation of search function using Binary search is available here
 * Assumes that the Array A is sorted NonDecreasingly
*/

#include "order.h"
int orderedsearch(Element x, Element A[], int N)
{
	int i,lo,hi,mid;
	lo=0;
	hi=N-1; 
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(A[mid]==x)
			return mid;
		else if (ordered(A[mid],x))
			lo=mid+1;
		else
			hi=mid-1;
	}
	return -3;
}
