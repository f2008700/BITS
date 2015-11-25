/* file: seqListOps.c */

#include "seqList.h"
#include <stdio.h>
#include<stdlib.h>


ListHead createList()
{
	ListHead h;
	h.next=NULL;
	h.size=0;
	return h;
}

Element getElement(int pos, ListHead h)
{
	int count=0;
	Link i;
	for(i=h.next;count<(pos-1);i=i->next,count++);
	return i->e;
}

/* Insert operations */
ListHead insertAtHead(Element e, ListHead h )
{
	Link nl;
	nl=(Link) malloc (sizeof(Node));
	nl->next=h.next;
	nl->e=e;
	h.next=nl;
	h.size++;
	return h;
}

ListHead insertAtTail(Element e, ListHead h )
{
	Link i,nl;
	nl=(Link) malloc (sizeof(Node));
	nl->e=e;
	nl->next=NULL;
	if(h.next==NULL)
		h.next=nl;
	else
	{
		for(i=h.next; i->next!=NULL;i=i->next);
		i->next=nl;
	}
	h.size++;
	return h;
}

ListHead insertInPos(Element e, ListHead h, int pos)
{
	Link i,nl;
	int count=0;
	nl=(Link) malloc (sizeof(Node));
	nl->e=e;
	if((h.next==NULL) &&(count==0))
	{
		nl->next=h.next;
		h.next=nl;
	}
	else
	{
		for(i=h.next; (count<pos && i->next!=NULL);count++,i=i->next);
		i->next=nl;
		nl->next=i->next;
	}
	h.size++;
	return h;
}


ListHead insertAfterValue(Element e, ListHead h, int val)
{
	Link i,nl;
	if(h.next!=NULL)
	{
		for(i=h.next; i!=NULL;i=i->next)
		{
			if(i->e.id==val)
			{
				nl=(Link) malloc (sizeof(Node));
				nl->e=e;
				nl->next=i->next;
				i->next=nl;
				h.size++;
			}
		}
	}
	return h;
}
/* Delete operations */

ListHead deleteFromHead(ListHead h)
{
	Link nl;
	if(h.next!=NULL)
	{
		nl=h.next;
		h.next=h.next->next;
		free(nl);
		h.size--;
	}
	return h;
}
ListHead deleteFromTail(ListHead h)
{
	Link nl;
	if(h.next!=NULL)
	{
		if(h.next->next==NULL)
		{
			free(h.next);
			h.next=NULL;
		}
		else
		{
			for(nl=h.next;nl->next->next!=NULL;nl=nl->next);
			free(nl->next);
			nl->next=NULL;
		}
		h.size--;
	}
	return h;
}
		
ListHead deleteValue(ListHead h, int val)
{
	Link nl,nl1;
	if(h.next!=NULL)
	{
		if(h.next->e.id == val)
		{
			nl1=h.next;
			h.next=h.next->next;
			free(nl1);
		}
		else
		{
			for(nl=h.next;nl!=NULL;nl1=nl,nl=nl->next)
			{
				if(nl->e.id == val)
				{
					nl1->next=nl->next;
					free(nl);
				}
			}
		}
		h.size--;
	}
	return h;
}

ListHead deletePos(ListHead h, int pos)
{
	Link nl,nl1;
	int count;
	if(h.next!=NULL)
	{
		if(pos==0)
		{
			nl1=h.next;
			h.next=h.next->next;
			free(nl1);
		}
		else
		{		
			count=1;
			for(nl=h.next; (count<pos &&  nl->next->next!=NULL); nl=nl->next,count++);
			if(count==pos)
			{
				nl1=nl->next;
				nl->next=nl->next->next;
				free(nl1);
			}
		}
		h.size--;
	}
	return h;
}


void printList(ListHead h)
{
	Link i;
	printf("The Student IDs in the List are\n");
	if(h.next!=NULL)
	{
		for ( i = h.next; i != NULL; i = i->next)
		{ 
			printf("%d,%d -->  ",i->e.id,i->e.regstatus);
		}
	}
}

