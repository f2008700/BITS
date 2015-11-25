#include<stdio.h>

int *largest(int *a, int *b);

int main()
{
	int x,y;
	int *p;
	x=30; y=20;
	p=largest(&x,&y);
	printf("The largest of %d and %d is %d\n",x,y,*p);
	return 0;
}

int *largest(int *a, int *b)
{
	if(*a>*b)
		return a;
	else
		return b;
}

