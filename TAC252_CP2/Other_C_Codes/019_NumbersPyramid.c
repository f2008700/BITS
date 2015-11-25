/*
The pyramid is a triangle formed by numbers...

          1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
  1 2 3 4 5 4 3 2 1
*/

# include <stdio.h>

void PrintSpace(int spaces)
{
	int count;
	for(count = 0; count < spaces; count++) printf("   ");
}

void PrintLine(int n, int limit)
{
	int i;
	PrintSpace(limit - n);
	
	for(i = 1; i < n; i++)printf("%3d", i);
	for(i = n; i > 0; i--)printf("%3d", i);
	printf("\n\n");
}


void main()
{
	int limit;
	int value;

	printf("Enter the no. of lines in the number pyramid..");
	scanf("%d", &limit);

	for(value = 1; value <= limit; value++) PrintLine(value, limit);
	printf("\n\n");
}