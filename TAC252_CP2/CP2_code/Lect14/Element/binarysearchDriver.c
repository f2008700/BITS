/* File Name searchDriver.c
 * Driver program for the search function is here
*/

#include<stdio.h>
#include"binarysearch.h"


int main()
{
//	Element A[]={4, 7, 10, 12, 14, 15, 19};
	Element A[]={19, 15, 14, 12, 10, 7, 4};
	int i,in,pos,size=7;
	printf("Enter the element to search\n");
	scanf("%d",&in);
	pos=orderedsearch(in, A, size);
	if(pos>-1)
		printf("The element %d exists in Array A[ %d ] location\n",in,pos);
	else
	{
		printf("The element %d does not exist in Array A\n",in);
		printf("return value from search function is  %d\n",pos);
		if(pos==-1)
			printf("search.c file executed\n");
		else if(pos==-2)
			printf("revsesearch.c file executed\n");
		else
			printf("binsearch.c file executed\n");
			
	}


	return 0;
} 
