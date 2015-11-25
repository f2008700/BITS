#include <stdio.h>
#include "setOps.h"

int main()
{
	Set S1, S2, S3;
	unsigned int x,M,N,i,Univ;
	printf("Enter the Universal Space\n");
	scanf("%d",&Univ);
	/********** Create Set S1 **********/
	CreateSet(S1,Univ);
	printf("S1 set is \n");
	PrintSet(S1,Univ);
	/********** Create Set S2 **********/
	CreateSet(S2,Univ);
	printf("S2 set is \n");
	PrintSet(S2,Univ);
	/* Create Set S3 *****************/
	CreateSet(S3,Univ);
	printf("S3 set is \n");
	PrintSet(S3,Univ);
	
	printf("Enter the number of Elements in S1 and S2\n");
	scanf("%d%d",&M,&N);
	/********* Add Elements to S1 ******/
	printf("Add Elements to S1\n");
	for(i=0;i<M;i++)
	{
		printf("Enter the Element\n");
		scanf("%d",&x);
		AddElementSet(x,S1,Univ);
	}
	printf("Add Elements to S2\n");
	for(i=0;i<N;i++)
	{
		printf("Enter the Element\n");
		scanf("%d",&x);
		AddElementSet(x,S2,Univ);
	}
	printf("The Set S1 after Addition\n");
	PrintSet(S1,Univ);
	printf("The Set S2 after Addition\n");
	PrintSet(S2,Univ);
	printf("Enter the Element to Delete from S1\n");
	scanf("%d",&x);
	RemoveElementSet(x,S1,Univ);
	printf("The Set S1 after Removal\n");
	PrintSet(S1,Univ);
	printf("Union of S1 and S2 sets are\n");
	UnionSet(S1,S2,S3,Univ);
	PrintSet(S3,Univ);
	printf("Intersection of S1 and S2 sets are\n");
	IntersectSet(S1,S2,S3,Univ);
	PrintSet(S3,Univ);
	printf("Complement of set S1 is\n");
	ComplementSet(S1,S2,Univ);
	PrintSet(S2,Univ);
	printf("Is set S1 EQUALS set S2 ?\n");
	if(EqualsSet(S1,S2,Univ))
		printf("The Sets are EQUAL\n");
	else
		printf("The Sets are NOT EQUAL\n");
	printf("Enter the value for finding element\n");
	scanf("%d",&x);
	if(isElementOfSet(x,S1,Univ))
		printf("The value %d is AVAILABLE in S1\n",x);
	else
		printf("The value %d is NOT AVAILABLE in S1\n",x);

return 0;
}
