#include<stdio.h>
#include<string.h>

typedef struct
{
	int ID;
	int Age;
	char Name[50];
}student;

int main()
{
	student s1,*ptr;
	s1.ID=2001222;
	s1.Age=23;
	strcpy(s1.Name,"Srinivas");

	ptr=&s1;

	printf("Printing s1\n");
	printf("ID = %d, Age = %d and Name = %s\n",s1.ID,s1.Age,s1.Name);


	printf("Printing ptr\n");
	printf("ID = %d, Age = %d and Name = %s\n",(*ptr.ID),(*ptr).Age,(*ptr).Name);


	printf("Printing ptr using -> operator\n");
	printf("ID = %d, Age = %d and Name = %s\n",ptr->ID,ptr->Age,ptr->Name);

	
	return 0;
}
