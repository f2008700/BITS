/* file name: figureOps.c */

#include "figure.h"
#include "boolean.h"
#include<stdio.h>
figure_t get_figure_dimension()
{
	figure_t f1;
	printf("Enter the shape. 0 for circle, 1 for square and 2 for rectangle\n");
	scanf("%d",&f1.shape);
	if(f1.shape==0)
	{
		printf("Enter radius of the circle\n");
		scanf("%lf",&f1.fig.cir.radius);
	}
	else if(f1.shape==1)
	{
		printf("Enter the side of square\n");
		scanf("%lf",&f1.fig.sq.side);
	}
	else if(f1.shape==2)
	{
		printf("Enter the length and width of rectangle\n");
		scanf("%lf",&f1.fig.rect.length, &f1.fig.rect.width);
	}
	else
		printf("Wrong option\n");
}

figure_t compute_area (figure_t f)
{
	if(f.shape==0)
		f.fig.cir.area=3.14*f.fig.cir.radius*f.fig.cir.radius;
	else if(f.shape==1)
		f.fig.sq.area=f.fig.sq.side*f.fig.sq.side;
	else if(f.shape==2)
		f.fig.rect.area=f.fig.rect.length*f.fig.rect.width;
	else
		printf("Wrong option; Not a specified shape\n");
}
figure_t compute_perimeter (figure_t f)
{
	if(f.shape==0)
		f.fig.cir.circumference=2.0*3.14*f.fig.cir.radius;
	else if(f.shape==1)
		f.fig.sq.perimeter=4.0*f.fig.sq.side;
	else if(f.shape==2)
		f.fig.rect.area=2.0*(f.fig.rect.length+f.fig.rect.width);
	else
		printf("Wrong option; Not a specified shape\n");

}
Boolean isEqual(figure_t f1, figure_t f2)
{
	if((f1.shape==0)&&(f2.shape==0))
	{
		if(f1.fig.cir.radius==f2.fig.cir.radius)
			return TRUE;
		else
			return FALSE;
	}
	else if((f1.shape==1)&&(f2.shape==1))
	{
		if(f1.fig.sq.side==f2.fig.sq.side)
			return TRUE;
		else
			return FALSE;
	}
	else if((f1.shape==2)&&(f2.shape==2))
	{
		if((f1.fig.rect.length==f2.fig.rect.length)&&(f1.fig.rect.width==f2.fig.rect.width))
			return TRUE;
		else
			return FALSE;
	}
	else
		printf("Wrong option; Not a specified shape\n");
return FALSE;
}
void print_figure(figure_t f1)
{
	if(f1.shape==0)
	{
		printf("%lf",f1.fig.cir.radius);
	}
	else if(f1.shape==1)
	{
		printf("%lf",f1.fig.sq.side);
	}
	else if(f1.shape==2)
	{
		printf("%lf",&f1.fig.rect.length, &f1.fig.rect.width);
	}
	else
		printf("Wrong option\n");
}

