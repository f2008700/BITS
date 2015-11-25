#include<stdio.h>

#include "search.h"
int main()
{
	Element X[]={100.5, 90.5, 80.3, 70.4, 60.6, 50.5, 40.4};
	int size=7;
	Element val=60.6;
	int pos;
	pos=search(val,X,size);
	if(pos>=0)
		printf("The position is %d\n",pos);
	else
		printf("Element is not available in array\n");


	return 0;
}

