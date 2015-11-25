#include<stdio.h>

int search(int x, int A[], int N);

int main()
{
	int X[]={10, 20, 30, 40, 50, 60, 70};
	int size=7;
	int val=30;
	int pos;
	pos=search(val,X,size);
	if(pos>=0)
		printf("The position is %d\n",pos);
	else
		printf("Element is not available in array\n");


	return 0;
}

int search(int x, int A[], int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(A[i]==x)
			return i;
		if(A[i]>x)
			return -1;
	}
	return -1;
}

