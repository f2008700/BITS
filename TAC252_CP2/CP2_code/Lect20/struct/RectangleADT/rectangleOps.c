/* file rectangleOps.c */
#include <stdio.h>
#include "rectangle.h"
#include "boolean.h"

Rect createRect(void)
{
	Rect R1={0,0};
	return R1;
}

Rect getData(Rect R1)
{
	printf("\nEnter the Length\n");
	scanf("%d",&R1.length);
	printf("Enter the Width\n");
	scanf("%d",&R1.width);
	return R1;
}

Boolean isSquare(Rect R1)
{
	if(R1.length==R1.width)
		return TRUE;
	else
		return FALSE;
}

Boolean isEqual(Rect R1, Rect R2)
{
	if((R1.length == R2.length) && (R1.width == R2.width))
		return TRUE;
	else
		return FALSE;
}

int computeArea(Rect R1)
{
	return (R1.length*R1.width);
}

int findMaxArea(Rect RA[], int N)
{
	int i,max=0;
	for(i=1;i<N;i++)
	{
		if((RA[max].length*RA[max].width)< (RA[i].length*RA[i].width))
			max=i;
	}
	return max;
}

void printRect(Rect R1)
{
	printf("The length is %d\n",R1.length);
	printf("The width is %d\n",R1.width);
}
