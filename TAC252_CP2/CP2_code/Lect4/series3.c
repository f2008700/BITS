/* 1 - (x/1!) + (x^2/2!) - ...... (x^N/N!)	*/

#include<stdio.h>

float term (int, int);
long int pow1 (int, int);
long int fact (int);

int main()
{
	int i,x,N;
	float Sum=0.0;
	printf("Enter x and N\n");
	scanf("%d %d",&x,&N);
	if(N>=0)
	{
		for(i=0;i<=N;i++)
			Sum=Sum+pow1(-1,i)*term(x,i);
	
		printf("The Sum = %f\n",Sum);
	}
	else
		printf("Wrong N value\n");
	return 0;
}

float term (int x, int k)
{
	int pow,fac;
	pow=pow1(x,k);
	fac=fact(k);
	return (float)pow/(float)fac;
}

long int pow1 (int x, int k)
{
	long int i,pow=1;
	for(i=0;i<k;i++)
		pow=pow*x;
	return pow;
}

long int fact (int k)
{
	long int i,fac=1;
	for(i=2;i<=k;i++)
		fac=fac*i;
	return fac;
}
