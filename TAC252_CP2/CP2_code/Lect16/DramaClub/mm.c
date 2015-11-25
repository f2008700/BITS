/* file: main.c */
#include<stdio.h>
#include "dramaClubOps.h"


int main()
{
	List A;
	Member x;
	ID id;
	ListSize N,temp;
	int i;
	printf("Enter the Number of elements\n");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("Enter the %d th element in LIST\n",i);
		scanf("%d",&A[i]);
	}
	printf("\n\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);

	printf("Enter the element to add in the LIST\n");
	scanf("%d",&x);
	temp=add(x,A,N);
	if(temp<N)
		printf("The List is FULL\n");
	else
		N=temp;
	printf("\n\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);

	printf("Enter the element to delete in the LIST\n");
	scanf("%d",&x);
	temp=delete(x,A,N);
	if(temp==N)
		printf("The Member is not EXISTING\n");
	else
		N=temp;
	printf("\n\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	
	printf("Enter the element to search in the LIST\n");
	scanf("%d",&x);
	printf("\n\n");
	if(isMember(x,A,N))
		printf("TRUE, %d is a MEMBER\n",x);
	else
		printf("FLASE, %d is NOT a MEMBER\n",x);
	return 0;
}
