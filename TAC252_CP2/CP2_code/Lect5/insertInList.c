/* Insert an element in a list of N elements. Before insertion it should check whether the element is present in the list or not if it is already there in the list then no need to insert and it should display the position of the element in the list*/

#include <stdio.h>
#define N 10

void Read_array( int a[], int size);
int Insert_element(int a[], int size, int pos, int value);
void Print_array(int a[], int size);
int IsPresent(int a[], int size, int value);

int main()
{
	int a[N], n, pos, i, val;
	printf("Enter the number of elements -- <=%d\n",N);
	scanf("%d",&n);
	printf("Enter the Array Elements\n");
	Read_array(a,n);
	printf("The Array Elements are:\n");
	Print_array(a,n);
	printf("Enter the data and position\n");
	scanf("%d %d",&val,&pos);
	if ((i=IsPresent(a,n,val))==-1)
	{
		n=Insert_element(a,n,pos,val);
		printf("Array after Insertion\n");
		Print_array(a,n);
	}
	else
	{
		printf("Data is present in position %d\n",i);
	}
	return 0;
}


void Read_array( int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
}

int Insert_element(int a[], int size, int pos, int value)
{
	int i;
	for(i=size-1;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=value;
	return ++size;
}


void Print_array(int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d\t",a[i]);
}

int IsPresent(int a[], int size, int value)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==value)
			return i;
	}
	return -1;
}
