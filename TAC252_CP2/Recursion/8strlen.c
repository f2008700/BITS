#include<stdio.h>


int len(char *str);

int main()

{

	char str[100];

	printf("Enter the character and string\n");

	scanf("%s",str);

	printf("The Length of the String %s is %d",str,len(str));

	return 0;

}


int len(char *str)

{

	if(str[0]=='\0')

		return 0;

	else

		return (1+len(&str[1]));

}
