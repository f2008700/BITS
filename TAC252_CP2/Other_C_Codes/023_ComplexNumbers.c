/*
This program is to read, write, add and multiply complex numbers.

Addition:  
(a+ib) + (x+iy) = (a+x) + i(b+y)

Multiplication:
(a+ib) * (x+iy) = (ax-by) + i(ay + bx)
*/

# include <stdio.h>

typedef struct
{
	double realPart;
	double imaginaryPart;
}ComplexNumber;

void ComplexNumber_Read(ComplexNumber *c)
{
	printf("\nEnter the real part...");
	scanf("%lf", &c->realPart);

	printf("\nEnter the imaginary part...");
	scanf("%lf", &c->imaginaryPart);
}

void ComplexNumber_Write(ComplexNumber *c)
{
	if(c->imaginaryPart < 0.0)	printf("%lf - i%lf", c->realPart, - c->imaginaryPart);
	else printf("%lf + i%lf", c->realPart, c->imaginaryPart);
}

void ComplexNumber_Add(ComplexNumber* a, ComplexNumber *b, ComplexNumber *sum)
{
	sum->realPart = a->realPart + b->realPart;
	sum->imaginaryPart = a->imaginaryPart + b->imaginaryPart;
}

void ComplexNumber_Multiply(ComplexNumber* a, ComplexNumber *b, ComplexNumber *product)
{
	product->realPart = (a->realPart * b->realPart) - (a->imaginaryPart * b->imaginaryPart);
	product->imaginaryPart = (a->realPart * b->imaginaryPart) + (a->imaginaryPart * b->realPart);
}


void main()
{
	ComplexNumber a, b, sum, product;

	printf("Enter two copmlex numbers....\n");
	ComplexNumber_Read(&a);
	ComplexNumber_Read(&b);

	ComplexNumber_Add(&a, &b, &sum);
	ComplexNumber_Multiply(&a, &b, &product);
	
	printf("\nThe sum is...");
	ComplexNumber_Write(&sum);

	printf("\nThe product is...");
	ComplexNumber_Write(&product);
}