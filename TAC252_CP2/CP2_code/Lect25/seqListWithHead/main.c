/* file main.c */
#include "seqListOps.h"
#include<stdio.h>
int main()
{
	int i,size=15;
	RegList rl;
	for(i=0;i<size;i++)
	{
		if(i%3==0)
		{
			rl[i].rs=SUCC;
			rl[i].st.i=i;
		}
		else if(i%3==1)
		{
			rl[i].rs=DENY;
			rl[i].st.i=i;
		}
		else
		{
			rl[i].rs=CON;
			rl[i].st.i=i;
		}
	}
	// R containing All (size number) registered student records
	ListHead ks, kd, kc;
	ks=createList();
	kd=createList();
	kc=createList();	 				
	for (i = 0; i < size; i++) {
		if  (rl[i].rs == DENY) {
	  		kd=insertRegInfo (rl[i], kd);
		} else if  (rl[i].rs == SUCC) {
			ks=insertRegInfo (rl[i], ks);
		} else {
			kc=insertRegInfo (rl[i], kc);
		}
	}
	printf("DENY LIST\n");
	printList(kd);

	printf("SUCCESS LIST\n");
	printList(ks);

	printf("CONFLICT LIST\n");
	printList(kc);
	
	//printf("COMPLETE LIST\n");
	//printStore(); 

	ks=deleteRegInfo(rl[0],ks);
	kd=deleteRegInfo(rl[4],kd);
	kc=deleteRegInfo(rl[5],kc);

	printf("DENY LIST After Deletion\n");
	printList(kd);

	printf("SUCCESS LIST After Deletion\n");
	printList(ks);

	printf("CONFLICT LIST After Deletion\n");
	printList(kc);
	
	//printf("COMPLETE LIST After Deletion\n");
	//printStore(); 


	return 0;
}

