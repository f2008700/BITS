#include <stdio.h>
#include "smallSetOps.h"

int main()
{
	SmallSet S1, S2, S3;
	int x,M,N,i;
	/********** Create Set S1 **********/
	S1=CreateSet();
	printf("S1 set is \n");
	Print(S1);
	/********** Create Set S2 **********/
	S2=CreateSet();
	printf("S2 set is \n");
	Print(S2);
	
	printf("Enter the number of Elements in S1 and S2\n");
	scanf("%d%d",&M,&N);
	/********* Add Elements to S1 ******/
	printf("Add Elements to S1\n");
	for(i=0;i<M;i++)
	{
		printf("Enter the Element\n");
		scanf("%d",&x);
		S1=AddElement(x,S1);
	}
	printf("Add Elements to S2\n");
	for(i=0;i<N;i++)
	{
		printf("Enter the Element\n");
		scanf("%d",&x);
		S2=AddElement(x,S2);
	}
	printf("The Set S1 after Addition\n");
	Print(S1);
	printf("The Set S2 after Addition\n");
	Print(S2);
	printf("Enter the Element to Delete from S1\n");
	scanf("%d",&x);
	S1=RemoveElement(x,S1);
	printf("Union of S1 and S2 sets are\n");
	S3=Union(S1,S2);
	Print(S3);
	printf("Intersection of S1 and S2 sets are\n");
	S3=Intersect(S1,S2);
	Print(S3);
	printf("Complement of set S1 is\n");
	S3=Complement(S1);
	Print(S3);
	printf("Is set S1 EQUALS set S2 ?\n");
	if(Equals(S1,S2))
		printf("The Sets are EQUAL\n");
	else
		printf("The Sets are NOT EQUAL\n");
	printf("Enter the value for finding element\n");
	scanf("%d",&x);
	if(isElementOf(x,S1))
		printf("The value %d is AVAILABLE in S1\n",x);
	else
		printf("The value %d is NOT AVAILABLE in S1\n",x);

return 0;
}
