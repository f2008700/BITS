/*
This program is to convert roman numbers into decimal numbers.

For eg. 

for input = "IV", the output should be "4"
*/

# include <stdio.h>

int Value(char romanDigit)
{
	if(romanDigit == 'I' || romanDigit == 'i') return 1;
	if(romanDigit == 'V' || romanDigit == 'v') return 5;
	if(romanDigit == 'X' || romanDigit == 'x') return 10;
	if(romanDigit == 'L' || romanDigit == 'l') return 50;
	if(romanDigit == 'C' || romanDigit == 'c') return 100;
	if(romanDigit == 'D' || romanDigit == 'd') return 500;
	if(romanDigit == 'M' || romanDigit == 'm') return 1000;

	return 0;
}

int Convert(char* romanNumber)
{
	int value1;
	int value2;

	value1 = Value(romanNumber[0]);
	if(value1 == 0) return 0;

	value2 = Value(romanNumber[1]);
	if(value2 == 0) return value1;

	if(value1 >= value2) return value1 + Convert(romanNumber+1);
	else return Convert(romanNumber+1) - value1;
}

void main()
{
	char romanNumber[128];
	int decimal;
	int onceMore;

	do
	{
		printf("Enter a roman number....");
		scanf("%s", romanNumber);

		decimal = Convert(romanNumber);
		printf("The converted no. is....%d\n", decimal);

		printf("Do you want to continue...[1/0]...");
		scanf("%d", &onceMore);
	}while (onceMore);
}