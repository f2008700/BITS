#include "stackOps.h"
#include<stdio.h>
#define size1 5
int main()
{
	int i;
	Element e;
	ElementList E;
	for(i=0;i<size1;i++)
	{
			E[i].id=i+1;
			E[i].regstatus=(i%3); //0= Success, 1 = Conflict, 2 = Deny
	}
	StackTop st,st1;
	st=createStack();
	
	st1=pop(st);
	if(st1.size==st.size)
		printf("POP failed ... Stack Empty\n");
	
	// Push 5 items
	for (i = 0; i < size1; i++)
		st=push(E[i],st);

	if(st.size>0)
	{
		e=top(st);
		if(e.id==0 && e.regstatus==-1)
			printf("\nEmpty Stack\n");
		else
		{
			printf("\nThe poped value is - id = %d and regstatus = %d\n",e.id,e.regstatus);
			st=pop(st);
		}
	}
	if(st.size>0)
	{
		e=top(st);
		if(e.id==0 && e.regstatus==-1)
			printf("Stack Empty\n");
		else
		{
			printf("\nThe poped value is - id = %d and regstatus = %d\n",e.id,e.regstatus);
			st=pop(st);
		}
	}

	for (i = 0; i < size1; i++)
		st=push(E[i],st);


	printf("\n\nThe stack content is\n");
	printStack(st);

	return 0;
}

