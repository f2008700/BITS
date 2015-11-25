#include<stdio.h>
#include<string.h>

struct student
{
	int ID;
	char Name[100];
	int AGE;
	float CGPA;
};  //No memory assigned here

int main()
{
	struct student s1; // Memory assigned here

	//Initialization of structure Method 1
	s1.ID=2009111;
	strcpy(s1.Name,"Arjun");
	s1.AGE=18;
	s1.CGPA=9.4;

	//Initialization of structure Method 2
	struct student s2={2009222,"Arun",19,8.9};

	//Can have variables with same name as structure members
	int ID;
	char Name[100];
	int AGE;
	float CGPA;

	//Can have variable with same name as structure tag
	int student;


	//Can not have variable same as structure variable
	//int s1;


	printf("s1.ID is %d\n",s1.ID);
	printf("s1.Name is %s\n",s1.Name);
	printf("s1.AGE = %d\n",s1.AGE);
	printf("s1.CGPA = %f\n",s1.CGPA);
	
	printf("s2.ID is %d\n",s2.ID);
	printf("s2.Name is %s\n",s2.Name);
	printf("s2.AGE = %d\n",s2.AGE);
	printf("s2.CGPA = %f\n",s2.CGPA);
	return 0;
}
