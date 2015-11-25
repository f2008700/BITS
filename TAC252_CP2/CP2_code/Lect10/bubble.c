#include<stdio.h>


void bubble(int List[], int N);

int main()
{
//	int A[]={20, 18, 15, 12, 9, 5, 3};
	int A[]={3, 5, 9, 12, 15, 18, 20};
	int i,size=7;
	bubble(A,size);
	printf("The sorted list is \n");
	for(i=0;i<size;i++)
		printf("%d\t",A[i]);
	printf("\n\n");
	return 0;
}

void bubble(int List[], int N)
{
	int i,j,temp,com;
	i=0;com=0;
	while(i<N)
	{
		j=0;
		while(j<(N-1))
		{
			com++;
			if(List[j]>List[j+1])
			{
				temp=List[j];
				List[j]=List[j+1];
				List[j+1]=temp;		
			}
			j++;
		}
		i++;
	}
	printf("The comparisons = %d\n",com);

}
