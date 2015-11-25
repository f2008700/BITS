/*
This program is to calculate the sum of n terms in the following series...

1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - x^10/10! + .... + n terms

here, the kth term is.... ((ix)^2k)/(2k!), k = 0, 1, 2, ..... , n

*/

# include <stdio.h>

double power(double x, int power)
{
	double value = 1.0;
	int count;
	for(count = 0; count < power; count++) value *= x;
	return value;
}

int factorial(int n)
{
	int value = 1;
	while(n > 0) value *= n--;
	return value;
}


void main()
{
	double x;
	int terms, count;
	double sum = 0.0;

	printf("Enter no. of terms in the series...");
	scanf("%d", &terms);

	printf("Enter x value....");
	scanf("%lf", &x);

	for(count = 0; count < terms; count++)
	{
		if(count%2) sum -= power(x, 2*count)/factorial(2*count);
		else sum += power(x, 2*count)/factorial(2*count);
	}

	printf("The sum of first %d terms in the series is %lf", terms, sum);

}