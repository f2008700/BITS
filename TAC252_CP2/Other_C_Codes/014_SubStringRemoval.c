/*
This program is to remove a part of the string.

For example, from the string "He has no fear", a sub string of size 3
starting from the position 6(including spaces) is removed, the output is

"He has fear"
*/

# include <stdio.h>

void Remove(char* string, int offset, int size)
{
	while(string[offset] = string[size+offset++]);
}

void main()
{
	char string[32] = "He has no fear";
	Remove(string, 6, 3);

	printf("The modified string is .. \n");
	printf("%s\n", string);
}