/* file: seqListOps.c */

#include "seqList.h"
#include <stdio.h>
int nextFreeLoc=0;
Store S;

ListHead createList()
{
	S[nextFreeLoc].next=-1;	
	nextFreeLoc++;
	return (nextFreeLoc-1);
}

Element getElement(int pos, ListHead h)
{
	int i,count=0;
	for(i=h;count<(pos-1);i=S[i].next,count++);
	return S[i].e;
}

void insertNode(Element e, ListHead h )
{
	int i;
	for(i=h; S[i].next!=-1;i=S[i].next);
	S[i].next=nextFreeLoc;
	S[nextFreeLoc].e=e;
	S[nextFreeLoc].next=-1;
	nextFreeLoc++;
}

void deleteNode(Element e, ListHead h)
{
	int i;
	for(i=h; S[i].next!=-1; i=S[i].next)
	{
		if(((S[S[i].next].e.id)==e.id) && ((S[S[i].next].e.regstatus)==e.regstatus))
		{
			S[i].next=S[S[i].next].next;
			break;
		}
	}
}

void insertInPos (Element e, ListHead h, int pos)
{ 	
	int i, count=0;
	for ( i = h; count < pos; i = S[i].next, count++) ;
	S[nextFreeLoc].e = e; 
	S[nextFreeLoc].next=S[i].next;
	S[i].next = nextFreeLoc;
	nextFreeLoc++;
}

void printList(ListHead h)
{
	int i;
	printf("The Student IDs in the List are\n");
	for ( i = S[h].next; S[i].next != -1; i = S[i].next)
	{ 
		printf("%d,%d -->  ",S[i].e.id,S[i].e.regstatus);
	}
		printf("%d,%d\n",S[i].e.id,S[i].e.regstatus);
}


void printStore()
{	int i;
	printf("The Student IDs in the store are\n");
	for ( i = 0; i<(MAX+3); i ++)
	{
		printf("%d --> ",S[i].e.id);
	}
}

