#include<stdio.h>

//#define fact(x) (x==0)? 1:x*fact(x-1)
#define square(x) x*x
#define swap(x,y) {int temp=x;x=y;y=temp;}

int main()
{
	int a,b,c;
	int temp;
	a=10;b=20;c=5;
//	fact(a);
	printf("%d ^ 2 = %d\n",a,square(a));
	printf("%d ^ 2 = %d\n",a+b,square(a+b));
//	printf("%d ^ 2 = %d\n",b,square(b++));
	printf("%d ^ 2 = %d\n",c,square(++c));

/*	printf("Before swap b=%d and c = %d\n",b,c); 
	swap(b,c);
	printf("After swap b=%d and c = %d\n",b,c); 
*/	return 0;
}
