#include<stdio.h>

inline int fact(int N);

int main()
{

	printf("%d\n",fact(5));
	return 0;
}

inline int fact(int N)
{
	if((N==0)||(N==1))
		return 1;
	else
		return (N*fact(N-1));
}
