#include<stdio.h>


int strcmp1(char s[], char t[]);
int strcmp2(char *s, char *t);
int strcmp3(char *s, char *t);

int main()
{

	char str1[]="program";
	char str2[]="prigram1";
	char str3[]="program";
	printf("From strcmp1 str1 - str2 = %d\n",strcmp1(str1,str2));
	printf("From strcmp1 str1 - str3 = %d\n",strcmp1(str1,str3));
	printf("From strcmp2 str1 - str2 = %d\n",strcmp2(str1,str2));
	printf("From strcmp2 str1 - str3 = %d\n",strcmp2(str1,str3));
	printf("From strcmp3 str1 - str2 = %d\n",strcmp3(str1,str2));
	printf("From strcmp3 str1 - str3 = %d\n",strcmp3(str1,str3));
	
	return 0;
}


int strcmp1(char s[], char t[])
{
	int i=0;
	while(s[i]==t[i])
	{
		if(s[i]=='\0') return 0;
		i++;
	}
	return (s[i]-t[i]);
}

int strcmp2(char *s, char *t)
{
	int i=0;
	while(*(s+i)==*(t+i))
	{
		if(*(s+i)=='\0') return 0;
		i++;
	}
	return (*(s+i)-*(t+i));
}

int strcmp3(char *s, char *t)
{
	while(*s==*t)
	{
		if(!*s) return 0;
		s++;t++;
	}
	return (*s-*t);
}

