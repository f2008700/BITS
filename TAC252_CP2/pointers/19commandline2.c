/*Sum and Average of N numbers */ 
#include<stdio.h>

int main(int argc, char *argv[])
{
	int i,sum=0;
	for(i=1;i<argc;i++)
		sum+=atoi(argv[i]);

	printf("Sum of %d numbers is %d\n",(argc-1),sum);
	printf("Average of %d numbers is %f\n",(argc-1),((float)sum)/(argc-1));	



	return 0;
}
