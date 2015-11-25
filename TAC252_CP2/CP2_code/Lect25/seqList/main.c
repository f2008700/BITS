/* file main.c */
#include "seqListOps.h"
#include<stdio.h>
int main()
{
	int i,size=15;
	RegList R;
	for(i=0;i<size;i++)
	{
		if(i%3==0)
		{
			R[i].rs=SUCC;
			R[i].st.i=i;
		}
		else if(i%3==1)
		{
			R[i].rs=DENY;
			R[i].st.i=i;
		}
		else
		{
			R[i].rs=CON;
			R[i].st.i=i;
		}
	}
	// R containing All (size number) registered student records
	ListHead ks, kd, kc;
	ks=createList();
	kd=createList();
	kc=createList();	 				
	for (i = 0; i < size; i++) {
		if  (R[i].rs == DENY) {
	  		insertRegInfo (R[i], kd);
		} else if  (R[i].rs == SUCC) {
			insertRegInfo (R[i], ks);
		} else {
			insertRegInfo (R[i], kc);
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

	deleteRegInfo(R[3],ks);
	deleteRegInfo(R[4],kd);
	deleteRegInfo(R[5],kc);

	printf("DENY LIST After Deletion\n");
	printList(kd);

	printf("SUCCESS LIST After Deletion\n");
	printList(ks);

	printf("CONFLICT LIST After Deletion\n");
	printList(kc);
	
	printf("COMPLETE LIST After Deletion\n");
	printStore(); 



}

