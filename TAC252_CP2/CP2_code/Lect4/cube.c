/* Cube of a number */
#include<stdio.h>
long int cube(int num);
int main()
{
	long int result;
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	result=cube(num);
	printf("Cube of %d = %d\n",num,result);

	result=cube(5);
	printf("Cube of %d = %d\n",5,result);
	return 0;
}
long int cube(int num)
{
	return (num*num*num);
}
