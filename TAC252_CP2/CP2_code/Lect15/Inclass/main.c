#include<stdio.h>
#include "head1.h"

int main()
{
	Element x,y,z;
	x='A', y=10;
	z=add(x,y);
	printf("The Result is %c\n",z);
	return 0;
}

