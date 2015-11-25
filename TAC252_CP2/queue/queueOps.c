
#include "queue.h"
#include <stdio.h>
#include<stdlib.h>
QueueHead createQueue()
{
	QueueHead q;
	q.front=NULL;
	q.rear=NULL;
	q.size=0;
	return q;
}





QueueHead EnQueue(Element e, QueueHead q)
{
	if(q.size<QueueSize)
	{
		QLink nl;
		nl=(QLink) malloc (sizeof(QFrame));
		if(nl!=NULL)
		{
			nl->next=NULL;
			nl->e=e;
			if(q.size>0)
				q.rear->next=nl;
			else
				q.front=nl;
			q.rear=nl;
			q.size++;
		}
		else
			printf("\nMemory Error.. malloc failed....\n");
	}
	else
		printf("\n\n Queue OverFlow\n");
	return q;
}


QueueHead DeQueue(QueueHead q)
{
	QLink nl;
	if(q.front!=NULL) // if(q.size>0)
	{
		if(q.size==1)
			q.rear=NULL;
		nl=q.front;
		q.front=nl->next;
		q.size--;
		free(nl);
	}
	else
		printf("Queue is Empty\n");
	return q;
}

Element front(QueueHead q)
{
	Element e;
	e.id=0;e.regstatus=-1;
	if(q.front!=NULL) //if(st.size>0)
		return q.front->e;
	return e;
}

void printQueue(QueueHead q)
{
	QLink i;
	printf("The Queue size = %d\n\n\n",q.size);
	for ( i = q.front; i != NULL; i = i->next)
	{ 
		printf("<---%d,%d ",i->e.id,i->e.regstatus);
	}
}

