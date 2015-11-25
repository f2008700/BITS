#include<stdio.h>

int add(int i, int j);

int main()
{
	int x,y,z;
	x=10, y=20;
	z=add(x,y);
	printf("The Result is %d\n",z);
	return 0;
}

int add(int i, int j)
{
	return (i+j);
}
