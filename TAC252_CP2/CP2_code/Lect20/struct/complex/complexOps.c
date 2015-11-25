/* file name: complexOps.h*/

#include<stdio.h>
#include<math.h>
#include "complexno.h"
#include "boolean.h"

complex_t create_complex()
{
	complex_t c={0.0,0.0};
	return c;
}

complex_t scan_complex(complex_t c)
{
	printf("Enter the Real and Imaginary terms\n");
	scanf("%lf %lf",&c.real,&c.img);
	return c;
}

void print_complex(complex_t c)
{
	printf("The real term is %lf\n",c.real);
	printf("The Imaginary term is %lf\n",c.img);
}


complex_t add_complex(complex_t c1, complex_t c2)
{
	complex_t sum;
	sum.real=c1.real+c2.real;
	sum.img=c1.img+c2.img;
	return sum;
}

complex_t sub_complex(complex_t c1, complex_t c2)
{
	complex_t diff;
	diff.real=c1.real-c2.real;
	diff.img=c1.img-c2.img;
	return diff;
		
}


complex_t abs_complex(complex_t c)
{
	complex_t cabs;
	cabs.real=sqrt(c.real*c.real+c.img*c.img);
	cabs.img=0;
	return cabs;
}


Boolean IsEqual(complex_t c1, complex_t c2)
{
	if ((c1.real==c2.real) && (c1.img==c2.img))
		return TRUE;
	else
		return FALSE;

}
