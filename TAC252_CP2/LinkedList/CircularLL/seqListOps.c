/* file: seqListOps.c */

#include "seqList.h"
#include <stdio.h>
#include<stdlib.h>


ListHead createList()
{
	ListHead h;
	h=(Link)malloc(sizeof(Node));
	if(h==NULL)
		printf("No sufficient Memory\n");
	h->next=NULL;
	return h;
}

Element getElement(int pos, ListHead h)
{
	int count=0;
	Link i;
	for(i=h->next;count<(pos-1);i=i->next,count++);
	return i->e;
}

/* Insert operations */
void insertAtHead(Element e, ListHead h )
{
	Link i,nl;
	nl=(Link) malloc (sizeof(Node));
	nl->e=e;
	if(h->next!=NULL)
	{
		for(i=h->next; i->next!= h->next;i=i->next);
		i->next=nl;
		nl->next=h->next;
	}
	else
		nl->next=nl;
	h->next=nl;
}

void insertAtTail(Element e, ListHead h )
{
	Link i,nl;
	nl=(Link) malloc (sizeof(Node));
	nl->e=e;
	if(h->next!=NULL)
	{
		for(i=h->next; i->next!=h->next;i=i->next);
		i->next=nl;
		nl->next=h->next;
	}
	else
	{
		nl->next=nl;
		h->next=nl;
	}
}

/* Delete operations */

void deleteFromHead(ListHead h)
{
	Link i,nl;
	if(h->next!=NULL)
	{
		nl=h->next;
		if(h->next->next!=h->next)
		{
			for(i=h->next;i->next!=h->next;i=i->next);
			i->next=h->next->next;
			h->next=h->next->next;
		}
		else
			h->next=NULL;
		free(nl);
	}
}
void deleteFromTail(ListHead h)
{
	Link nl;
	if(h->next!=NULL)
	{
		for(nl=h;nl->next->next!=h->next;nl=nl->next);
		free(nl->next);
		nl->next=h->next;
	}
}
		
void printList(ListHead h)
{
	Link i;
	printf("The Student IDs in the List are\n");
	for ( i = h->next; i->next != h->next; i = i->next)
	{ 
		printf("%d,%d -->  ",i->e.id,i->e.regstatus);
	}
	if(i!=NULL)
		printf("%d,%d -->  ",i->e.id,i->e.regstatus);
		
}

