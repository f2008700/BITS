#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct
{
	int ID;
	char Name[50];
	int Age;
}student;

void sort(student *A, int N);


int main()
{
	int i;
	student *A;
	A=(student *) malloc(MAX*sizeof(student));
	printf("Enter Input Valuses\n");
	for(i=0;i<MAX;i++)
	{
		printf("Enter the ID\n");
		scanf("%d",&A[i].ID);
		printf("Enter the Age\n");
		scanf("%d",&A[i].Age);
		printf("Enter the Name\n");
		scanf("%s",A[i].Name);
	}

	printf("\nA before sorting\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",A[i].ID);
	
	sort(A,MAX);

	printf("\nA after sorting\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",A[i].ID);
	free(A);
	return 0;
}

void sort(student *A, int N)
{
	int sorted=0;
	int j,i=0;
	student temp;
	while ((i<N) && (sorted==0))
	{ 
		j=0; sorted=1;
		while ( j < (N-i-1) )
		{
			//if(A[j].ID> A[j+1].ID)
			if((*(A+j)).ID> (*(A+j+1)).ID)
			{
				temp=*(A+j);      //temp=A[j];
				*(A+j)=*(A+j+1);  //A[j]=A[j+1];   
				*(A+j+1)=temp;    //A[j+1]=temp;
				sorted=0;
			}
			j++;
		}
		i++;
	}
}
