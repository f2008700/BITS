/*
This program will find the largest and the smallest values among the 
given set of numbers.
*/

# include <stdio.h>

void main()
{
	int smallest, largest;
	int count, number;

	printf("Enter the no. of numbers...");
	scanf("%d", &count);

	if(count <= 1)
	{
		printf("Atleast two numbers are required..");
		return;
	}

	printf("Enter a value....");
	scanf("%d", &number);
	smallest = largest = number;

	for( ; count > 1; count--)
	{
		printf("Enter a value....");
		scanf("%d", &number);

		if(smallest > number) smallest = number;
		if(largest < number) largest = number;
	}

	printf("The smallest no. is....%d\n", smallest);
	printf("The largest no. is....%d\n", largest);


}