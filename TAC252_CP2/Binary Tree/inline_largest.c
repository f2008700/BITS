#include<stdio.h>

inline int largest(int a, int b)
{
	if(a>b) return a;
	else return b;
}


int main()
{
	int x,y,z;
	x=20;
	y=10;
	z=30;
	printf("largest of %d, %d is %d\n",x,y,largest(x,y);
	printf("largest of %d, %d is %d\n",y,z,largest(y,z);
	printf("largest of %d, %d is %d\n",x,z,largest(x,z);

	return 0;
}
