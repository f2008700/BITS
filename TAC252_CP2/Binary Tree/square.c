#include<stdio.h>

#define square(x) x*x

int main()
{
	int a,b,c;
	a=10;b=20;c=5;
	printf("%d ^ 2 = %d\n",a,square(a));
	printf("%d ^ 2 = %d\n",b,square(b));
	printf("%d ^ 2 = %d\n",c,square(c));
	
	return 0;
}
