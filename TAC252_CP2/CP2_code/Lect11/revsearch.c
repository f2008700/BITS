/* File Name: revsearch.c
 * implementation of search function using Linear search (Reverse) is available here
*/

int search(int x, int A[], int N)
{
	int i;
	for(i=N-1;i>=0;i--)
	{
		if(A[i]==x)
			return i;
	}
	return -2;
}
