#include<stdio.h>

struct student
{
	int ID;
	char Name[100];
	int AGE;
	float CGPA;
};

struct stu
{
	int ID;
	int AGE;
	char Name[100];
	float CGPA;
};

struct stu1
{
	int ID;
	char Name[100];
	int AGE;
	float CGPA;
};

int main()
{
	struct student s1={2009333,"Avinash",20,9.3};
	
	struct student s2=s1; //copy the content of one struct to another 
		//Name of the struct with no component selection operator refers to the entire structure

	struct stu ss1;
	//ss1=s1; --> Not allowed	
	struct stu1 ss2;
	//ss2=s1; --> Not allowed	

	printf("The s1 details\n");
	printf("ID=%d\t Name: %s\t AGE=%d\t CGPA=%f\n",s1.ID,s1.Name,s1.AGE,s1.CGPA);


	printf("The s2 details\n");
	printf("ID=%d\t Name: %s\t AGE=%d\t CGPA=%f\n",s2.ID,s2.Name,s2.AGE,s2.CGPA);





	return 0;
}
