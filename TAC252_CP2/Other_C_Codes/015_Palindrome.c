/*
This program checks if the given string is a palindrome or not
*/

# include <stdio.h>

int strlen(char *string)
{
	int length = 0;
	while(string[length++]);
	return length - 1;
}

void CheckForPalindrome(char* string)
{
	int length = strlen(string);
	int loop;
	
	for(loop = 0; loop < length/2; loop++)
	{
		if(string[loop] != string[length-loop-1])
		{
			printf("The given string is not a palindrome\n");
			return;
		}
	}

	printf("The given string is a palindrome\n");
}


void main()
{	
	CheckForPalindrome("malayalam");
}