/* file main.c */
#include "seqListOps.h"
#include<stdio.h>
int main()
{
	int i,size=15;
	ElementList E;
	Element e1;
	e1.id=2000;
	e1.regstatus=0;
	for(i=0;i<size;i++)
	{
			E[i].id=i;
			E[i].regstatus=(i%3); //0= Success, 1 = Conflict, 2 = Deny
	}
	// R containing All (size number) registered student records
	ListHead ks, kd, kc;
	ks=createList();
	kd=createList();
	kc=createList();	 				
	for (i = 0; i < size; i++) {
		if  (E[i].regstatus == 0) {
	  		insertAtTail (E[i], ks);
		} else if  (E[i].regstatus == 1) {
			insertAtHead (E[i], kc);
		} else {
			insertInPos (E[i], kd,2);
		}
	}
	insertAfterValue (e1, ks, 3);
	printf("\n\nSUCCESS LIST\n");
	printList(ks);

	printf("\n\nCONFLICT LIST\n");
	printList(kc);

	printf("\n\nDENY LIST\n");
	printList(kd);


	deleteFromHead(ks);
	deleteFromTail(kc);
	deleteValue(kd,8);
	deletePos(ks,0);

	printf("\n\nSUCCESS LIST After Deletion\n");
	printList(ks);

	printf("\n\nCONFLICT LIST After Deletion\n");
	printList(kc);

	printf("\n\nDENY LIST After Deletion\n");
	printList(kd);
	

}

