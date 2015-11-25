/* File Name: search.c
 * implementation of search function using Linear search is available here
*/

int search(int x, int A[], int N)
{
	int i; 
	for(i=0;i<N;i++)
	{
		if(A[i]==x)
			return i;
	}
	return -1;
}
