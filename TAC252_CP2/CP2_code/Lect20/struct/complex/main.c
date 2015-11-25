#include <stdio.h>
#include "complexOps.h"

int main()
{
	//Create a complex number
	complex_t com1,com2,Addcom,Subcom,Abscom;
	
	com1=create_complex();
	com2=create_complex();
	printf("The complex Number 1 is\n");
	print_complex(com1);
	printf("The complex Number 2 is\n");
	print_complex(com2);

	//Get data from User
	com1=scan_complex(com1);
	com2=scan_complex(com2);
	printf("The complex Number 1 After scan is\n");
	print_complex(com1);
	printf("The complex Number 2 After scan is\n");
	print_complex(com2);

	// Add and Sub with complex numbers
	Addcom=add_complex(com1,com2);
	Subcom=sub_complex(com1,com2);
	Abscom=abs_complex(com1);
	
	printf("The Add result is\n");
	print_complex(Addcom);
	printf("The Sub Result is\n");
	print_complex(Subcom);
	printf("The Abs valus of com1 is\n");
	print_complex(Abscom);

	if(IsEqual(com1,com2))
		printf("Complex number 1 is EQUAL to complex number 2\n");
	else
		printf("Complex number 1 is NOT EQUAL to complex number 2\n");

	
	return 0;
}
