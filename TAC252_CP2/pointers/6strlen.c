#include<stdio.h>


int strlen1(char *s);
int strlen2(char *s);
int strlen3(char *s);
int strlen4(char *s);

int main()
{

	char str1[]="program";
	printf("strlen1 output = %d\n",strlen1(str1));
	printf("strlen2 output = %d\n",strlen2(str1));
	printf("strlen3 output = %d\n",strlen3(str1));
	printf("strlen4 output = %d\n",strlen4(str1));
	
	return 0;
}

int strlen1(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}

int strlen2(char *s)
{
	int i;
	for(i=0;*(s+i)!='\0';i++);
	return i;
}
int strlen3(char *s)
{
	char *p=s;
	while(*p!='\0')
		p++;
	return (p-s);
}
int strlen4(char *s)
{
	char *p=s;
	while(*p++);
	return (p-s-1);
}

