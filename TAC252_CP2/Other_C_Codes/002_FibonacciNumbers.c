/*

The following program is to generate n terms in the fibonacci series.

fibonacci series is defined as......

a(n) = a(n-1) + a(n-2)

and a(0) = 0, a(1) = 1

the first 5 terms in the fibonacci series are....
0, 1, 1, 2, 3

the first 10 terms in the fibonacci series are...
0, 1, 1, 2, 3, 5, 8, 13, 21, 34
*/

# include <stdio.h>

void main()
{
	int terms;
	int firstPrevious = 1, secondPrevious = 0;
	int count;

	printf("Enter the no. of terms in the fibanocci series....");
	scanf("%d", &terms);

	printf("The first %d terms in the fibanocci series are....\n", terms);
	if(terms >= 2) printf("0 1 ");
	else if(terms == 1) printf("0 ");

	for(count = 2; count < terms; count++)
	{
		printf("%d ", firstPrevious + secondPrevious);
		firstPrevious += secondPrevious;
		secondPrevious = firstPrevious - secondPrevious;
	}
}