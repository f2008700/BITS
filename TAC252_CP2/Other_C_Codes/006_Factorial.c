/*
This program is to find the Factorial of a number.

factorial is defined as....

n! = 1*2*3*...*(n-2)*(n-1)*n

*/

int recursiveFactorial(int value)
{
	if(value <= 1) return 1;
	else return value*recursiveFactorial(value-1);
}

int nonRecursiveFactorial(int value)
{
	int factorial = 1;
	while(value > 1) factorial *= value--;
	return factorial;
}

void main()
{
	int number;
	printf("Enter a number...");	
	scanf("%d", &number);

	printf("The recursive factorial is....%d\n", recursiveFactorial(number));
	printf("The non-recursive factorial is....%d\n", nonRecursiveFactorial(number));
}