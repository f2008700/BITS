#include<stdio.h>


int main()

	{


	
	 int i=10;
	
	 int *ptr,*ptr1,*ptr2;
	
	 ptr=&i;
	
	 ptr1=ptr++;
	
	 ptr2=ptr1++;

	
	 printf("the value of i = %d\n the address of MEM where i is stored is %u\n\n",i, &i);
	
	 printf("the value of ptr = %u\n and the address of MEM where ptr is stored is %u\n\n",ptr, &ptr);
		         
	 printf("The size of memory allocated for i is %d\n\n",sizeof(i));
	
	 printf("The size of memory allocated for ptr is %d\n\n",sizeof(ptr));

	
	 printf("The value in MEM pointed by ptr is %d\n\n",*ptr);



	
	 printf("ptr = %u\t ptr1 = %u\t ptr2 = %u\t ptr2-ptr = %d\n",ptr,ptr1,ptr2,ptr2-ptr);


	
	 return 0;

	}
