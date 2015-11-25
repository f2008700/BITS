/* file: seqListOps.c */


#include "seqList.h"

#include <stdio.h>

int nextFreeLoc=0;

Store S;


ListHead createList()

	{
	
	 S[nextFreeLoc].next=-1;
	
 nextFreeLoc++;
	
	 return (nextFreeLoc-1);
	
}


RegInfo getRegInfo(int pos, ListHead h)

	{
	
	 int i,count=0;
	
	 for(i=h;count<(pos-1);
	 i=S[i].next,count++);
	
	 return S[i].ri;

	}


void insertRegInfo(RegInfo R, ListHead h )
	
{
	
	 int i;
	
	 for(i=h; S[i].next!=-1;i=S[i].next);
	
	 S[i].next=nextFreeLoc;
	
	 S[nextFreeLoc].ri=R;
	
	 S[nextFreeLoc].next=-1;
	
	 nextFreeLoc++;

	}


void deleteRegInfo(RegInfo R, ListHead h)
	
{
	
	 int i;
	
	 for(i=h; S[i].next!=-1; i=S[i].next)
	
		{
		
		 if(((S[S[i].next].ri.st.i)==R.st.i) && ((S[S[i].next].ri.st.y)==R.st.y))
		
			{
			
			 S[i].next=S[S[i].next].next;
			
			 break;
		
			}
	
		}

	}


void insertInPos (RegInfo R, ListHead h, int pos)

	{ 	
	
	 int i, count=0;
	
	 for ( i = h; count < pos; i = S[i].next, count++) ;
	
	 S[nextFreeLoc].ri = R; 
	
	 S[nextFreeLoc].next=S[i].next;
	
	 S[i].next = nextFreeLoc;
	
	 nextFreeLoc++;

	}


void printList(ListHead h)
	
{
	
	 int i;
	
	 printf("The Student IDs in the List are\n");
	
	 for ( i = S[h].next; S[i].next != -1; i = S[i].next)
	
		{ 
		
		 printf("%d -->  ",S[i].ri.st.i);
	
		}
		
	 printf("%d\n",S[i].ri.st.i);

	}



void printStore()

	{	
	 int i;
	
	 printf("The Student IDs in the store are\n");
	
	 for ( i = 0; i<(MAX+3); i ++)
	
		{
		
		 printf("%d --> ",S[i].ri.st.i);
	
		}
	
}

