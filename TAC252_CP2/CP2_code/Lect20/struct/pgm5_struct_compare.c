#include<stdio.h>
typedef struct
{
	int length;
	int width;
}Rectangle;


int compare(Rectangle R1, Rectangle R2);

int main()
{
	Rectangle Re1, Re2, Re3;
	Re1.length=10; Re1.width=20;
	Re2.length=20; Re2.width=10;
	Re3.length=10; Re3.width=20;
	if(compare(Re1,Re2))
		printf("Re1 and Re2 are EQUAL\n");
	else
		printf("Re1 and Re2 are NOT EQUAL\n");

	if(compare(Re1,Re3))
		printf("Re1 and Re3 are EQUAL\n");
	else
		printf("Re1 and Re3 are NOT EQUAL\n");
	return 0;
}

int compare(Rectangle R1, Rectangle R2)
{
	if((R1.length==R2.length)&&(R1.width==R2.width))
		return 1;
	else
		return 0;
}
