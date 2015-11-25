#include<stdio.h>

int main()
{
	int i,j,l,x,u,k,temp,N=8;
	int A[]={10, 15, 12, 16, 30, 18, 32, 11};
	printf("The Array before the operation is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\n");
	printf("Enter the K value (1 to N) \n");
	scanf("%d",&k);
	l=0; u=N-1;k--;
	while(l<u)
	{
		i=l; j=u;
		x=A[k];
		while((i<=k)&&(j>=k))
		{
			while(A[i]>x)i++;
			while(A[j]<x)j--;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i++; j--;
		}
		if(j<k) l=i;
		if(i>k) u=j;
	}
	printf("The Array After the operation is:\n");
	for(i=0;i<N;i++)
		printf("%d\t",A[i]);
	printf("\nThe %d th larget is position is %d\n",(k+1),A[k]);
	return 0;
}
