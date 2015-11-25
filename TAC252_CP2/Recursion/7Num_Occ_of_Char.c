#include<stdio.h>


int count(char c, char *str);

int main()

{

	char ch,str[100];

	printf("Enter the character and string\n");

	scanf("%c %s",&ch,str);

	printf("The number of Occurrence of %c in %s is %d",ch,str,count(ch,str));

	return 0;

}


int count(char c, char *str)

{

	if(str[0]=='\0')

		return 0;

	else if(str[0]==c)

		return (1+count(c,&str[1]));

	else

		return (count(c,&str[1]));

}
