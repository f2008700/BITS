#include "queueOps.h"
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
	QueueHead q,q1;
	q=createQueue();
	
	q1=DeQueue(q);
	if(q1.size==q.size)
		printf("DeQueue failed ... Queue Empty\n");
	
	// EnQueue 5 items
	for (i = 0; i < size1; i++)
		q=EnQueue(E[i],q);

	if(q.size>0)
	{
		e=front(q);
		if(e.id==0 && e.regstatus==-1)
			printf("\nEmpty Queue\n");
		else
		{
			printf("\nThe poped value is - id = %d and regstatus = %d\n",e.id,e.regstatus);
			q=DeQueue(q);
		}
	}
	if(q.size>0)
	{
		e=front(q);
		if(e.id==0 && e.regstatus==-1)
			printf("Queue Empty\n");
		else
		{
			printf("\nThe poped value is - id = %d and regstatus = %d\n",e.id,e.regstatus);
			q=DeQueue(q);
		}
	}

	for (i = 0; i < size1; i++)
		q=EnQueue(E[i],q);


	printf("\n\nThe Queue content is\n");
	printQueue(q);

	return 0;
}

