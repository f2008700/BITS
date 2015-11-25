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
	h->prev=NULL;
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
	Link nl;
	nl=(Link) malloc (sizeof(Node));
	nl->next=h->next;
	nl->prev=h;
	nl->e=e;
	if(h->next!=NULL)
		h->next->prev=nl;
	h->next=nl;
}

void insertAtTail(Element e, ListHead h )
{
	Link i,nl;
	for(i=h; i->next!=NULL;i=i->next);
	nl=(Link) malloc (sizeof(Node));
	nl->e=e;
	nl->next=NULL;
	nl->prev=i;
	i->next=nl;
}

void insertInPos(Element e, ListHead h, int pos)
{
	Link i,nl;
	int count=0;
	for(i=h; (count<pos && i->next!=NULL);count++,i=i->next);
	nl=(Link) malloc (sizeof(Node));
	nl->e=e;
	nl->next=i->next;
	nl->prev=i;
	if(i->next!=NULL)
		i->next->prev=nl;
	i->next=nl;
}


void insertAfterValue(Element e, ListHead h, int val)
{
	Link i,nl;
	for(i=h; i!=NULL;i=i->next)
	{
		if(i->e.id==val)
		{
			nl=(Link) malloc (sizeof(Node));
			nl->e=e;
			nl->next=i->next;
			nl->prev=i;
			if(i->next!=NULL)
				i->next->prev=nl;
			i->next=nl;
		}
	}
}
/* Delete operations */

void deleteFromHead(ListHead h)
{
	Link nl;
	if(h->next!=NULL)
	{
		nl=h->next;
		if(h->next->next!=NULL)
			h->next->next->prev=h;
		h->next=h->next->next;
		free(nl);
	}
}
void deleteFromTail(ListHead h)
{
	Link nl;
	if(h->next!=NULL)
	{
		for(nl=h;nl->next->next!=NULL;nl=nl->next);
		free(nl->next);
		nl->next=NULL;
	}
}
		
void deleteValue(ListHead h, int val)
{
	Link nl,nl1;
	if(h->next!=NULL)
	{	
		for(nl=h->next;nl!=NULL;nl1=nl,nl=nl->next)
		{
			if(nl->e.id == val)
			{
				if(nl->next!=NULL)
					nl->next->prev=nl1;
				nl1->next=nl->next;
				free(nl);
			}
		}
	}
}

void deletePos(ListHead h, int pos)
{
	Link nl,nl1;
	int count;
	if(h->next!=NULL)
	{
		count=0;
		for(nl=h; (count<pos &&  nl->next->next!=NULL); nl=nl->next,count++);
		if(count==pos)
		{
			nl1=nl->next;
			nl->next=nl->next->next;
			free(nl1);
		}
	}
}


void printList(ListHead h)
{
	Link i;
	printf("The Student IDs in the List are\n");
	for ( i = h->next; i != NULL; i = i->next)
	{ 
		printf("%d,%d (%d)-->  ",i->e.id,i->e.regstatus,i->prev->e.id);
		
	}
}

