/*
This program is to search for the first occurance of the 

substring mentioned in a string.


for example, "go" is found at position 6 in "He is good"
NOTE: the first index is 0 (not 1)
*/

# include <stdio.h>

int strlen(char *string)
{
	int length = 0;
	while(string[length++]);
	return length - 1;
}

int search(char* string, char* text)
{
	int offset = 0;
	int textSize = strlen(text);
	int textOffset = 0;

	while(string[offset])
	{
		if(text[textOffset] == string[offset])
		{
			textOffset++;
			if(textOffset == textSize) return offset - textSize + 1;
		}
		else textOffset = 0;
		offset++;
	}
	return -1;
}


void main()
{
	int position = search("He is good", "go");
	printf("The text is found at...%d\n", position);
}