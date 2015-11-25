/* File Name searchDriver.c
 * Driver program for the search function is here
*/

#include<stdio.h>
#include<math.h>
#include "quad.h"
int main()
{
	int a,b,c,sign;
	float res;
	printf("Enter a, b, c and sign for the quadratic equation\n");
	scanf("%d %d %d %d",&a,&b,&c,&sign);
	res=quad(a,b,c,sign);
	if(res!=-1.0000)
		printf("The sol for quad equ is %f\n",res);
	else
		printf("Wrong entry for a, b, c, and sign\n");
	return 0;
} 
