/*
Pascals triangle is a triangle formed by numbers...

         1
        1 1
       1 2 1
      1 3 3 1
     1 4 6 4 1


 each line in the Pascal's triangle represents the 
 terms in the expansion (1 + x)^n, 
 where n = 0, 1, 2... and x = 1

 for eg. for n = 2, the pascal's numbers are..

(1 + x)^2 = 1 + 2x + x^2
(1 + 1)^2 = 1 + 2 + 1

(1 + x)^3 = 1 + 3x + 3x^2 + x^3
(1 + 1)^3 = 1 + 3 + 3 + 1
*/

# include <stdio.h>

//  n           n!
//   C   =  ---------
//    r     (n-r)!.r! 
int nCr(int n, int r)
{
	int numerator = 1;
	int denominator = 1;
	int count;

	if(n < 2) return 1;

	for(count = 0; count < r; count++)
	{
		numerator *= n--;
		denominator *= (r-count);
	}

	return numerator/denominator;	
}

void PrintSpace(int spaces)
{
	int count;
	for(count = 1; count < spaces; count++) printf("   ");
}

void PrintLine(int n, int limit)
{
	int i;
	PrintSpace(limit - n);
	
	for(i = 0; i <= n; i++)
	{
		printf("%6d", nCr(n, i));
	}
	printf("\n\n");
}


void main()
{
	int limit;
	int value;

	printf("Enter the no. of lines in the Pascal's triangle..");
	scanf("%d", &limit);

	for(value = 0; value < limit; value++) PrintLine(value, limit);
	printf("\n\n");
}