/* file: seqListOps.c */

#include "seqList.h"
#include <stdio.h>
#include <stdlib.h>
int nextFreeLoc=0;
Store S;

ListHead createList()
{
	ListHead h;
	h.start=-1;
	h.size=0;
	return h;
}

RegInfo getRegInfo(int pos, ListHead h)
{
	int i,count=0;
	if(pos>=h.size)
	{
		printf("Wrong pos. Exiting\n");
		exit(0);
	}
	for(i=h.start;count<(pos-1);i=S[i].next,count++);
	return S[i].ri;
}

ListHead insertRegInfo(RegInfo R, ListHead h )
{
	int i;
	if(h.size==0)
	{
		h.start=nextFreeLoc;
	}
	else
	{
		for(i=h.start; S[i].next!=-1;i=S[i].next);
		S[i].next=nextFreeLoc;
	}
	S[nextFreeLoc].ri=R;
	S[nextFreeLoc].next=-1;
	nextFreeLoc++;
	h.size++;
	return h;
}

ListHead deleteRegInfo(RegInfo R, ListHead h)
{
	int i, oldi, count=0;
	if(h.size<=0)
	{
		printf("No Element in the List ... Exiting\n");
		exit(1);
	}
	
	if(((S[h.start].ri.st.i)==R.st.i))
	{
		h.start=S[h.start].next;
		h.size--;
		return h;
	}
	oldi=h.start;
	for(i=h.start; count<h.size; i=S[i].next, count++)
	{
		if(((S[i].ri.st.i)==R.st.i))
		{
			S[oldi].next=S[i].next;
			h.size--;
			break;
		}
		oldi=i;
	}
	return h;
}

ListHead insertInPos (RegInfo R, ListHead h, int pos)
{ 	
	int i, count=0;
	if(pos>=h.size)
	{
		printf("Wrong pos ... exiting\n");
		exit(3);
	}
	S[nextFreeLoc].ri = R;
	if((h.size==0)|| (pos==0))
	{
		if(pos==0)
			S[nextFreeLoc].next=h.start;
		else
			S[nextFreeLoc].next=-1;
		h.start=nextFreeLoc;
	}
	else
	{
		for ( i = h.start; count < (pos-1); i = S[i].next, count++) ;
		S[nextFreeLoc].next=S[i].next;
		S[i].next = nextFreeLoc;
	}
	nextFreeLoc++;
	h.size++;
	return h;
}

void printList(ListHead h)
{
	int i;
	if(h.size<=0)
	{
		printf("No Elements in List\n");
		exit(4);
	}
	printf("The Student IDs in the List are\n");
	for ( i = h.start; S[i].next != -1; i = S[i].next)
	{ 
		printf("%d -->  ",S[i].ri.st.i);
	}
		printf("%d\n",S[i].ri.st.i);
}


void printStore()
{	int i;
	printf("The Student IDs in the store are\n");
	for ( i = 0; i<(MAX); i ++)
	{
		printf("%d --> ",S[i].ri.st.i);
	}
}

