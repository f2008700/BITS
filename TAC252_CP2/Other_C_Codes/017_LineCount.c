/*
This program counts the no. of lines, words and characters
in a give n statement.

For eg.... the text

He is intelligent.
But he is not good at programming.

contains.....
two lines.
ten words
53 characters

*/
# include <stdio.h>

int IsAlphabet(char c)
{
	if(c <= 'Z' && c >= 'A') return 1;
	if(c <= 'z' && c >= 'a') return 1;
	return 0;
}

void main()
{
	char* text =  "He is intelligent.\nBut he is not good at programming.";
	int lines = 1;
	int words = 0;
	int characters = 0;

	char c = text[characters++];

	while(c)
	{
		if(IsAlphabet(c))
		{
			words++;
			while(IsAlphabet(c)) c = text[characters++];
		}		
		if(c == '\n') lines++;
		c = text[characters++];
	}

	printf("The string is....\n\n%s\n\n", text);

	printf("The no. of lines is........%d\n", lines);
	printf("The no. of words is........%d\n", words);
	printf("The no. of characters is...%d\n", characters - 1);

}