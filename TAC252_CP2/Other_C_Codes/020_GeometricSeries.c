/*

Program to find the sum of first n terms of a geometric progression

sum = 1 + x + x^2 + x^3 + x^4 + .... + x^n

for x = 3, n = 3

sum = 1 + 3 + 9 + 27 = 40
*/

# include <stdio.h>

double power(double x, int n)
{
	double value = 1.0;
	while(n-- > 0) value *= x;
	return value;
}

double sum(double x, int n)
{
	double value = 0.0;
	while(n >= 0) value += power(x, n--);
	return value;
}

void main()
{
	double x;
	int n;

	printf("Enter the values of x and n..");
	scanf("%lf%d", &x, &n);

	if(n >= 0) printf("The sum is...%lf\n", sum(x, n));
	else printf("Invalind input");
}