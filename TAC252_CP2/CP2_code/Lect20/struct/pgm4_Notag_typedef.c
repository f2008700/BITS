#include<stdio.h>
#include<string.h>
struct 
{
	int ID;
	char Name[100];
	int AGE;
	float CGPA;
}stu1;


typedef struct
{
	int ID;
	char Name[100];
	int AGE;
	float CGPA;
}student;   //User defined data type.



int main()
{
	stu1.ID=2009444;
	strcpy(stu1.Name,"Sidharth");
	stu1.AGE=21;
	stu1.CGPA=9.6;

	student s1={2009009,"Karan",21,9.7};

	printf("The stu1 ID is %d\t Name is %s\t Age is %d\t and CGPA is %f\n",stu1.ID,stu1.Name,stu1.AGE,stu1.CGPA);
	printf("\n\nThe s1 ID is %d\t Name is %s\t Age is %d\t and CGPA is %f\n",s1.ID,s1.Name,s1.AGE,s1.CGPA);

	return 0;
}
