/* Sum of 2 numbers */
#include<stdio.h>
int sum(int a, int b);
int main()
{
	int x,y,result;
	printf("Enter x and y\n");
	scanf("%d %d",&x,&y);
	sum(x,y);
	printf("Result = %d\n",result);
	return 0;
}
int sum(int a, int b)
{
	return (a+b);
}
