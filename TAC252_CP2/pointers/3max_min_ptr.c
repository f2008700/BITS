#include<stdio.h>


void max_min(int *A, int N, int *max, int *min);


int main()
	
{
	
	 int A[]={2,22,10,1,28,6,9,21};
	
	 int N=8;
	
	 int max, min;
	
	 max_min(A,N,&max,&min);

	
	 printf("Max = %d and Min = %d\n",max,min);
	
	 return 0;
	 
}


void max_min(int *A, int N, int *max, int *min)
	
{
	
	 int i;
	
	 *max=*A;
	
	 *min=*A;
	
	 A++;
	
	 for(i=1;i<N;i++)
	
		{
		
		 if(*max<*A)
			
		 *max=*A;
		
		 if(*min>*A)
			
		 *min=*A;
		
		 A++;
	
	 }
	
}

