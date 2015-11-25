#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct
{
        int ID;
        char Name[50];
        int Age;
}student;

void sort(student **P, int N);

int main()
{
        int i;
        student *A, **B;
        A=(student *) malloc(MAX*sizeof(student));
	B=(student **)malloc(MAX*sizeof(student *));
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
	for(i=0;i<MAX;i++)
		B[i]=&A[i];

	printf("\nA before sorting\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",(*B[i]).ID);
	
	sort(B,MAX);

	printf("\nA after sorting\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",(*B[i]).ID);
	
	printf("\nThe Original Array after sorting\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",A[i].ID);
	return 0;
}

void sort(student **P, int N)
{
	int sorted=0;
	int j,i=0;
	student *temp;
	while ((i<N) && (sorted==0))
	{ 
		j=0; sorted=1;
		while ( j < (N-i-1) )
		{
			if((*(P[j])).ID > (*(P[j+1])).ID)
			{
				temp=P[j];
				P[j]=P[j+1];
				P[j+1]=temp;
				sorted=0;
			}
			j++;
		}
		i++;
	}
}
