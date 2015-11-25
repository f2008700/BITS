#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

int palin(char *str);
int main()
{
	char *s=(char *)malloc(MAX*sizeof(char));
	printf("Enter the string\n");
	scanf("%s",s);
	if(palin(s))
		printf("The string %s is a Palindrom\n",s);
	else
		printf("The string %s is not a Palindrom\n");

	return 0;
}

int palin(char *str)
{
	char *f,*r;
	for(f=str,r=(str+strlen(str)-1);f<r;f++,r--)
		if(*f!=*r)
			return 0;
	return 1;
}
