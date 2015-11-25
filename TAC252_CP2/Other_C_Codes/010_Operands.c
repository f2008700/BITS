/*
This progam takes a number, an operation and another number

and computes the result, based on them

for eg.

for the input "2 + 3", the output should be 5
for the input "2 % 3", the output should be 2
*/

# include <stdio.h>

void main()
{
	char operation[32];
	int operand1, operand2;
	int result = 0;

	printf("Enter the operand1, operation and operand2...");
	scanf("%d%s%d", &operand1, &operation, &operand2);

	switch(operation[0])
	{
	case '-':
		result = operand1 - operand2;
	break;

	case '+':
		result = operand1 + operand2;
	break;

	case '*':
		result = operand1 * operand2;
	break;
	
	case '/':
		result = operand1 / operand2;
	break;

	case '%':
		result = operand1 % operand2;
	break;
	}

	printf("The result is.....%d\n", result);
}