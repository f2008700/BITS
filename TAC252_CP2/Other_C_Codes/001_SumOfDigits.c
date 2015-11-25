/*
This program is to calculate the individual digits of a given number.

For example, if 123 is the input,

the output should be 1 + 2 + 3 = 6

for input 124, the output should be 7
*/


int SumOfDigits(int value)
{
	int sum = 0;

	while(value > 0)
	{
		sum += value % 10;
		value /= 10;
	}

	return sum;
}

void main()
{
	int number, sum;

	printf("Enter a number...");
	scanf("%d", &number);

	sum = SumOfDigits(number);
	printf("The sum of digits of the given number is ... %d", sum);
}