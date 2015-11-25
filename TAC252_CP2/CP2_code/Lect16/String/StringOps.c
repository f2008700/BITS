/* File name: StringOps.h */

#include "String.h"
#include <stdio.h>
#include <string.h>


/* Pre cond: memory allocation for text 
 *       Post cond: input text is stored in text  */
void createString(String text)
{
	gets(text);
}


  /* Pre cond: text should not be empty 
     Post cond: input text is printed */
void printString(String text)
{
	puts(text);
}


/* Pre cond: Text should have atleast one word 
 *      Post cond: returns index position of word, if present, else returns -1  */
Position findWord(String text, String word)
{
	Position i,j;
	String temp;
	int wordlen=strlen(word);
	int paralen=strlen(text);
	i=0;
	while(i<paralen)
	{
		while((text[i]==' ')|| (text[i]=='\0'))i++;
		j=0;
		while(j<wordlen)
		{
			if(text[i]!=word[j])
			{
				while(((text[i]!=' ')&&(i!=paralen)))i++;
				break;
			}
			j++;i++;
		}
		if(j==wordlen)
		{
			if((text[i]==' ') || (i==paralen))
			{
				return (i-j);
			}
		}
	}
	return 0;
}

 /* Pre cond: There should be enough room for insertion;
 *      0=pos <length(text)     
 *          Post cond: returns length of Text after insertion*/
Size insertWord(String text, Position index, String newWd)
{
	int wordlen=strlen(newWd);
	int paralen=strlen(text);
	Position i,j;
	for(i=paralen;i>=index;i--)
		text[i+wordlen+1]=text[i];
	for(i=index,j=0;j<wordlen;i++,j++)
		text[i]=newWd[j];
	text[i]=' ';
	return (wordlen+paralen+1);

}

 /* Pre cond: text and word should not be empty 
    Post cond text after removing first occurance of the word */
Size deleteWord(String text, String word)
{
	Position i;
	int paralen=strlen(text);
	int wordlen=strlen(word);
	Position pos=findWord(text,word);
	printf("The position is %d\n",pos);
	if(pos>=0)
	{
		for(i=pos;i<=(paralen-wordlen);i++)
		{
			text[i]=text[i+wordlen+1];
		}
		return (paralen-wordlen-1);
	}
	return 0;
}


