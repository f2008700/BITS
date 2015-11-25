
#include "stack.h"
#include <stdio.h>
#include<stdlib.h>

StackTop createStack()
{
	StackTop st;
	st=(Link)malloc(sizeof(Frame));
	if(st==NULL)
		printf("No sufficient Memory\n");
	st->next=NULL;
	return st;
}

void push(Element e, StackTop st)
{
	Link nl;
	nl=(Link) malloc (sizeof(Frame));
	if(nl!=NULL)
	{
		nl->next=st->next;
		nl->e=e;
		st->next=nl;
	}
	else
		printf("\nMemory Error.. malloc failed....\n");
}


Element pop(StackTop st)
{
	Link nl;
	Element e;e.id=0;e.regstatus=-1;
	if(st->next!=NULL)
	{
		nl=st->next;
		e=st->next->e;
		st->next=st->next->next;
		free(nl);
	}
	else
		printf("Stack is Empty\n");
	return e;
}


void printStack(StackTop st)
{
	Link i;
	printf("The Student IDs in the Stack are\n");
	for ( i = st->next; i != NULL; i = i->next)
	{ 
		printf("%d,%d -->  ",i->e.id,i->e.regstatus);
	}
}

