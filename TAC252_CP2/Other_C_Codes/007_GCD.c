/*

This program is to find the greatest common divisor (GCD) of the 
give n two numbers.

for eg. GCD of 7 and 14 = 7

there are many efficient algorithms to find the gcd

only two algorithms are selected.

both of these should give the same result

I din't check them.  Feel free to check if they are right or wrong
*/

# include <stdio.h>

int slowGCD(int a, int b)
{
	int loop;
	for(loop = (a>b)?b:a; loop >= 1; loop--)
	{
		if( (a % loop) == 0 && (b % loop) == 0) return loop;
	}
}

int fastGCD(int a, int b)
{	
	while( a > 1 && b > 1)
	{
		if(a > b)
		{			
			if((a%b) == 0) return b;
			a = a % b;
			
		}
		else if(b > a)
		{
			if((b%a) == 0) return a;
			b = b % a;
		}
		else return a;
	}

	return 1;
}

int recursiveGCD(int a, int b)
{
	if(a > b)
	{
		if(a%b == 0) return b;
		return recursiveGCD(a%b, b);
	}
	else if( b > a)
	{
		if(b%a == 0) return a;
		return recursiveGCD(a, b%a);
	}
	else return a;

}

void main()
{
	int a, b;
	int gcd;

	printf("Enter two numbers....");
	scanf("%d%d", &a, &b);
	
	gcd = fastGCD(a, b);
	printf("The fast GCD of %d and %d is...%d\n", a, b, gcd);

	gcd = slowGCD(a, b);
	printf("The slow GCD of %d and %d is...%d\n", a, b, gcd);

	gcd = recursiveGCD(a, b);
	printf("The recursive GCD of %d and %d is...%d\n", a, b, gcd);
	
}