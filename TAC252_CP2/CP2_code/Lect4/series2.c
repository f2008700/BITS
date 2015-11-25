/* 1 - x + x^2 - ...... x^N	*/

#include<stdio.h>

long int pow1 (int, int);

int main()
{
	int i,x,N;
	long int Sum=0;
	printf("Enter x and N\n");
	scanf("%d %d",&x,&N);
	if(N>=0)
	{
		for(i=0;i<=N;i++)
			Sum=Sum+(pow1(-1,i)*pow1(x,i));
	
		printf("The Sum = %ld\n",Sum);
	}
	else
		printf("Wrong N value\n");
	return 0;
}

long int pow1 (int x, int k)
{
	int i,pow=1;
	for(i=0;i<k;i++)
		pow=pow*x;
	return pow;
}
