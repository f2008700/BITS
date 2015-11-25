#include<stdio.h>


void strcpy1(char s[], char t[]);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t);
void strcpy4(char *s, char *t);
void strcpy5(char *s, char *t);

int main()
{

	char str1[]="program";
	char str2[10];
	strcpy1(str1,str2);
	printf("str2 after strcpy1 = %s\n",str2);
	strcpy2(str1,str2);
	printf("str2 after strcpy2 = %s\n",str2);
	strcpy3(str1,str2);
	printf("str2 after strcpy3 = %s\n",str2);
	strcpy4(str1,str2);
	printf("str2 after strcpy4 = %s\n",str2);
	strcpy5(str1,str2);
	printf("str2 after strcpy5 = %s\n",str2);
	
	return 0;
}


void strcpy1(char s[], char t[])
{
	int i=0;
	while((t[i]=s[i]) !='\0') i++;
}

void strcpy2(char *s, char *t)
{
	int i=0;
	while((t[i]=s[i]) !='\0') i++;
}

void strcpy3(char *s, char *t)
{
	while(*s=*t !='\0') { s++;t++; }
}

void strcpy4(char *s, char *t)
{
	while(*s++=*t++ !='\0');
}

void strcpy5(char *s, char *t)
{
	while(*s++=*t++);
}
