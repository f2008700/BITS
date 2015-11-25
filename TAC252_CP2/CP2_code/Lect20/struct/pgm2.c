#include<stdio.h>
struct point
{
	int x; int y;
};

//Hierarchical structures --> struct containing components that are data structures
//(Array or structures)
struct line
{
	struct point start;
	struct point end;
};

struct rect
{
	struct line lines[4];
};

int main()
{
	struct point p1={10,20};
	struct point p2;
	p2.x=100; p2.y=200;
	
	struct line L1={{10,20},{100,200}};

	printf("p1.x is %d\t p1.y = %d\n",p1.x,p1.y);
	printf("p2.x is %d\t p2.y = %d\n",p2.x,p2.y);
	printf("L1.start.x is %d\t L1.start.y = %d\n",L1.start.x,L1.start.y);
	printf("L1.end.x is %d\t L1.end.y = %d\n",L1.end.x,L1.end.y);
	



	return 0;
}
