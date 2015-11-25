#include<stdio.h>
#include<string.h>

typedef struct
{
	char stName[50];
	int PIN;
}Address;
typedef struct
{
	int *ID;
	int Age;
	char Name[50];
	Address *add;
}student;

int main()
{
	int i;
	student *ptr;
	student s1[4];
	Address a1[4];

	int id[4]={2001222,2001333,2001444,2001555};
	for(i=0;i<4;i++)
	{
		s1[i].ID=(id+i);
		s1[i].Age=23;
		strcpy(s1[i].Name,"Srinivas");
	}
	for(i=0;i<4;i++)
	{
		strcpy(a1[i].stName,"12thCross");
		a1[i].PIN=560004;
		s1[i].add=(a1+i);
	}
	printf("Printing s1 Array\n");
	for(i=0;i<4;i++)
	{
		printf("ID = %d, Age = %d and Name = %s\n",*((s1+i)->ID),(s1+i)->Age,(s1+i)->Name);
		printf("street Name = %s and PIN = %d\n",(s1+i)->add->stName,(s1+i)->add->PIN);
	}
	ptr=s1;
	

	printf("Printing s1 array by using ptr\n");
	for(i=0;i<4;i++)
	{
		printf("ID = %d, Age = %d and Name = %s\n",*((ptr+i)->ID),(ptr+i)->Age,(ptr+i)->Name);
		printf("street Name = %s and PIN = %d\n",(ptr+i)->add->stName,(ptr+i)->add->PIN);
	}
	
	return 0;
}
