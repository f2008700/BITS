#include<stdio.h>
#include "String.h"

int main()
{
	String para, word;
	Position pos;
	Size s;
	printf("Enter the paragraph\n");
	createString(para);
	printf("\n\nThe Entered paragraph is:   ");
	printString(para);
	printf("\n\nEnter the word\n");
	scanf("%s",word);
	pos=findWord(para,word);
	printf("\n\nThe position of the word is %d\n",pos);
	printf("Enter the position in which the word to be added\n");
	scanf("%d",&pos);
	printf("Enter the word to add\n");
	scanf("%s",word);
	s=insertWord(para,pos,word);
	printf("The new para after insertion is with %d length :\n",s);
	printString(para);
	printf("Enter the word to be deleted\n");
	scanf("%s",word);	
	s=deleteWord(para,word);
	printf("The new para after deletion is with %d length :\n",s);
	printString(para);	
	return 0;
}
