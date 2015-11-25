/*
This program will find the roots of a quadratic equation

the roots are... (-b ± sqrt(b^2-4ac))/2a
*/
# include <math.h>
# include <stdio.h>

void main()
{
	double a, b, c;
	double delta;
	double real, imaginary;
	double root1, root2;

	printf("Enter the a, b and c values of the quadratic equation..");
	scanf("%lf%lf%lf", &a, &b, &c);

	printf("The roots are....");

	delta = b*b - 4*a*c;
	if(delta < 0.0)
	{
		real = -b/(2*a);
		imaginary = fabs(sqrt(-delta)/(2.0*a));

		printf("(%lf + i%lf) and (%lf -i%lf)\n", real, imaginary, real, imaginary);
	}
	else
	{
		root1 = (-b + sqrt(delta))/(2*a);
		root2 = (-b - sqrt(delta))/(2*a);
		printf("%lf and %lf\n", root1, root2);
	}
}