/*
This program is to insert a string at a given position of another string.

for eg. 

if " not" is to be inserted after 5 charecters (including spaces)
in the string.. "He is a good boy",

the output will be "He is not a good boy"

*/


void Insert(char* string1, char* string2, int position, char* output)
{
	int i;
	for(i = 0; i < position; i++) *output++ = *string1++;
	while(*string2) *output++ = *string2++;
	while(*output++ = *string1++);
}

void main()
{
	char* string1 = "He is a good boy";
	char* string2 = " not";
	char output[128];

	Insert(string1, string2, 5, output);
	printf("The modified string is.....\n%s\n", output);
}