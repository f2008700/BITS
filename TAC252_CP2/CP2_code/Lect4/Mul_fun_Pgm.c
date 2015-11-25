/* Develop a modular program using functions that reads the values of the three sides of the a triangle and displays either its area or its perimeter as per the user request
 */

#include<stdio.h>
#include<math.h>

float ReadSide();
float perimeter(float a,float b, float c);
float area(float a, float b, float c);
void display(float a, float b, float c);

int main()
{
	int i;
	float a,b,c;
	a=ReadSide();
	b=ReadSide();
	c=ReadSide();
	display(a,b,c);
	return 0;
}

float ReadSide()
{
	float x;
	printf("Enter the side\n");
	scanf("%f",&x);
	return x;
}
void display (float a, float b, float c)
{
	int choice;
	printf("Enter your choice 0 for Area 1 for Perimeter\n");
	scanf("%d",&choice);
	if(choice==0)
		printf("The Area = %f\n",area(a,b,c));
	else if(choice ==1)
		printf("The Perimeter = %f\n",perimeter(a,b,c));
	else
		printf("Wrong Option\n");
}

float area(float a, float b, float c)
{
	float s,res;
	s=(a+b+c)/2;
	res= sqrt((s-a)*(s-b)*(s-c));
	return res;
}

float perimeter(float a, float b, float c)
{
	return (a+b+c);
}



