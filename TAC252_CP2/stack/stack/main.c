#include "stackOps.h"
#include<stdio.h>
#define size 5
int main()
{
	int i;
	Element e;
	ElementList E;
	for(i=0;i<size;i++)
	{
			E[i].id=i+1;
			E[i].regstatus=(i%3); //0= Success, 1 = Conflict, 2 = Deny
	}
	StackTop st;
	st=createStack();
	
	e=pop(st);
	if(e.id==0 && e.regstatus==-1)
		printf("\nEmpty Stack\n");
	// Push 5 items
	for (i = 0; i < size; i++)
		push(E[i],st);
	e=pop(st);
	if(e.id==0 && e.regstatus==-1)
		printf("\nEmpty Stack\n");
	else
		printf("\nThe poped value is - id = %d and regstatus = %d\n",e.id,e.regstatus);
	
	e=pop(st);
	if(e.id==0 && e.regstatus==-1)
		printf("Stack Empty\n");
	else
		printf("\nThe poped value is - id = %d and regstatus = %d\n",e.id,e.regstatus);
	
	
	printf("\n\nAfter %d pushes and 2 pops the stack content is\n",size);
	printStack(st);

	return 0;
}
// Uses
// Undo operation in Any Editor
// Back Button in browser
// Previous instructions executed in Linux Command prompt
//
