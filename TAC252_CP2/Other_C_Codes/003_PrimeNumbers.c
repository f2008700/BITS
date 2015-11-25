/*
This program is to display the prime numbers between 1 and n

for eg. 

for n = 5, the output is "2 3 5"

for n = 10, the output is "2 3 5 7"
*/

# include <stdio.h>

void CheckForPrimeNumber(int value)
{
	int count;
	for(count = 2; count < value/2; count++) if(value%count == 0) return;
	printf("%d ", value);
}

void main()
{
	int limit, count;
	printf("Enter the maximum limit of prime numbers...");
	scanf("%d", &limit);

	printf("The prime numbers between 1 and %d are...\n", limit);

	for(count = 2; count <= limit; count++)
		CheckForPrimeNumber(count);
}