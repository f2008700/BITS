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
	student s1,*ptr;
	Address a1;
	int id=2001222;
	s1.ID=&id;
	s1.Age=23;
	strcpy(s1.Name,"Srinivas");

	strcpy(a1.stName,"12thCross");
	a1.PIN=560004;

	s1.add=&a1;

	printf("Printing s1\n");
	printf("ID = %d, Age = %d and Name = %s\n",*(s1.ID),s1.Age,s1.Name);
	printf("street Name = %s and PIN = %d\n",s1.add->stName,s1.add->PIN);

	ptr=&s1;


	printf("Printing ptr\n");
	printf("ID = %d, Age = %d and Name = %s\n",*(ptr->ID),ptr->Age,ptr->Name);
	printf("street Name = %s and PIN = %d\n",ptr->add->stName,ptr->add->PIN);
	
	return 0;
}
