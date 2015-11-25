/* file main.c */
#include "seqListOps.h"
#include<stdio.h>
int main()
{
	int i,size=15;
	ElementList E;
	for(i=0;i<size;i++)
	{
			E[i].id=i;
			E[i].regstatus=(i%3); //0 success, 1 = deny, 2 = conflict
	}
	// R containing All (size number) registered student records
	ListHead ks, kd, kc;
	createStore();
	ks=createList();
	kd=createList();
	kc=createList();	 				
	for (i = 0; i < size; i++) {
		if  (E[i].regstatus == 2) {
	  		insertNode (E[i], kd);
		} else if  (E[i].regstatus == 0) {
			insertNode (E[i], ks);
		} else {
			insertNode (E[i], kc);
		}
	}
	printf("DENY LIST\n");
	printList(kd);

	printf("SUCCESS LIST\n");
	printList(ks);

	printf("CONFLICT LIST\n");
	printList(kc);
	
	printf("COMPLETE LIST\n");
	printStore(); 

	deleteNode(E[3],ks);
	deleteNode(E[4],kd);
	deleteNode(E[5],kc);

	printf("DENY LIST After Deletion\n");
	printList(kd);

	printf("SUCCESS LIST After Deletion\n");
	printList(ks);

	printf("CONFLICT LIST After Deletion\n");
	printList(kc);
	
	printf("COMPLETE LIST After Deletion\n");
	printStore(); 



}

