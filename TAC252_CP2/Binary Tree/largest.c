#include<stdio.h>

#define largest(x,y) x>y

int main()
{
	int a,b,c;
	a=10;b=20;c=5;
	if(largest(a,b))
		printf("%d is greater than %d\n",a,b);
	else
		printf("%d is greater than %d\n",b,a);
	if(largest(b,c))
		printf("%d is greater than %d\n",b,c);
	else
		printf("%d is greater than %d\n",c,b);
	return 0;
}
