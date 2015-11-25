/* X ^ Y Generic Solution - Top down design */

#include<stdio.h>

int main()
{
	int i,X,Y,result;
	printf("Enter X and Y\n");
	scanf("%d %d",&X,&Y);
	if(Y>0)
	{
		result = X; /* Atomic Solution */
		for(i=0; i<(Y-1); i++)
			result = result * X;
		printf("The Result = %d\n",result);
	}
	else if (Y==0)
		printf("The Result = 1\n");
	else
		printf("Take a Positive Y value\n");
	return 0;
}
