/* file name: selection.c */

#include "compare.h"

void insert(Member m, List l, int N);



void insertionsort(List A, int N)
{
	int i,j,min,pos,x;
	for(i=1;i<N;i++)
		insert(A[i], A, i);
}



void insert(Member m, List l, int N)
{
	int i,j;
	for(i=0;i<N;i++)
		if(compare(m,l[i]))
			break;
	for(j=(N-1);j>=i;j--)
		l[j+1]=l[j];
	l[i]=m;
}

