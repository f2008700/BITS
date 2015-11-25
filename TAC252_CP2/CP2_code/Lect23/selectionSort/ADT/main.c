#include<stdio.h>
#include "selection.h"

int main()
{
	int i,N;
	List A={55, 44, 77, 88, 22, 33, 99, 11, 66};
	N=9;
	printf("\nThe Array before sorting\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	selectionsort(A,N);
	printf("\n\nThe Array After sorting\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	return 0;
}

