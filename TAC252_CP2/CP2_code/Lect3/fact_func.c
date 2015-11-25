/* Program for (z + x)! + (y!/x!) */
#include<stdio.h>
int fact(int x);
int main()
{
	int x,y,z,i,z_x;
	int fact_z_x, fact_y, fact_x;
	printf("Enter X, Y and Z\n");
	scanf("%d %d %d",&x,&y,&z);
	if (((z+x)>=0) && (y>=0) && (x >0))
	{
		fact_z_x=fact(z+x);
		fact_y=fact(y);
		fact_x=fact(x);
		printf("fact_z_x = %d fact_y = %d and fact_x = %d\n",fact_z_x, fact_y, fact_x);
		printf("The final result is %d\n",(fact_z_x + fact_y / fact_x));
	}
	else
		printf("Problem is not solvable. Try with different input values\n");
	return 0;
}

int fact (int a)
{
	int i,result=1;
	for(i=2; i<=a; i++)
		result = result * i;
	return result;
}


