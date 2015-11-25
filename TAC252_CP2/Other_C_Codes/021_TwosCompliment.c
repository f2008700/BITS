/*
This program is to find the two's compliment of a given binary number.

technically, 2's compliment of a number is nothing but
inverting it's sign.

for example, if 3 is represented as 00000000 00000011 in 16 bit form,
it's two's compliment is ...........11111111 11111101
and this is nothing but the representation of -3
if you add these two numbers, you will get "1 00000000 00000000"
the left most bit is discarded, as we are talking about 16 bit numbers

2's compliment is obtained by.....
complimenting all the bits that are to the left side of the right most 1


But, relax.... 
in this program we are not going use this shortcut


eg. (for 8 bits)

number....3
binary....00000011
2's comp..11111101

number....4
binary....00000100
2's comp..11111100
*/

# include <stdio.h>

int strlen(char *string)
{
	int length = 0;
	while(string[length++]);
	return length - 1;
}


void TwosCompliment(char* number, char* compliment)
{
	int length = strlen(number);
	int index = length;
	int loop;

	while(index >= 0 && number[index] != '1') index--;

	for(loop = 0; loop < index; loop++)		compliment[loop] = '1' + '0' - number[loop];

	compliment[index] = '1';

	for(loop = index + 1; loop < length; loop++) compliment[loop] = '0';
	
	compliment[length] = 0;
}

void main()
{
	char number[128];
	char compliment[128];

	printf("Enter a binary number.......");
	scanf("%s", number);

	TwosCompliment(number, compliment);

	printf("It's two's compliment is....%s", compliment);
}