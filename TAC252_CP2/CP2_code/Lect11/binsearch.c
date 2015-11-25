/* File Name: binsearch.c
 * implementation of search function using Binary search is available here
 * Assumes that the Array A is sorted NonDecreasingly
*/

int search(int x, int A[], int N)
{
	int i,lo,hi,mid;
	lo=0;
	hi=N-1; 
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(A[mid]==x)
			return mid;
		else if (A[mid]>x)
			hi=mid-1;
		else
			lo=mid+1;
	}
	return -3;
}
