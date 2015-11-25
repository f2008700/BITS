/* X ^ Y, where Y = 2 ^ k Solution - Top down design */

#include<stdio.h>
#include<math.h>

int main()
{
	int i,X,Y,k,result;
	printf("Enter X and Y\n");
	scanf("%d %d",&X,&Y);
	if(Y>0)
	{
		result = X; /* Atomic Solution */
		k=ceil((log(Y))/(log(2)));
		for(i=0; i<k; i++)
			result = result * result;
		printf("The Result = %d\n",result);
	}
	else if (Y==0)
		printf("The Result = 1\n");
	else
		printf("Take a Positive Y value\n");
	return 0;
}
