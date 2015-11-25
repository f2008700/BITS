
#include "stack.h"
#include <stdio.h>
#include<stdlib.h>
StackTop createStack()
{
	StackTop st;
	st.size=0;
	printf("The size of st is %d\n",st.size);
	st.top=NULL;
	return st;
}

StackTop push(Element e, StackTop st)
{
	if(st.size<StackSize)
	{
		Link nl;
		nl=(Link) malloc (sizeof(Frame));
		if(nl!=NULL)
		{
			nl->next=st.top;
			nl->e=e;
			st.top=nl;
			st.size++;
		}
		else
			printf("\nMemory Error.. malloc failed....\n");
	}
	else
		printf("\n\n Stack OverFlow\n");
	return st;
}


StackTop pop(StackTop st)
{
	Link nl;
	if(st.top!=NULL) // if(st.size>0)
	{
		nl=st.top;
		st.top=st.top->next;
		st.size--;
		free(nl);
	}
	else
		printf("Stack is Empty\n");
	return st;
}

Element top(StackTop st)
{
	Element e;
	e.id=0;e.regstatus=-1;
	if(st.top!=NULL) //if(st.size>0)
		return st.top->e;
	return e;
}

void printStack(StackTop st)
{
	Link i;
	printf("The stack size = %d\n\n\n",st.size);
	for ( i = st.top; i != NULL; i = i->next)
	{ 
		printf("%d,%d -->  ",i->e.id,i->e.regstatus);
	}
}

