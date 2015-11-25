/* file: main.c */
#include <stdio.h>
#include "rectangleOps.h"

int main()
{
	Rect Re1, Re2, Re3;
	Rect RA[100];
	int i,N;
	/* Create Re1 and Re2 */
	Re1=createRect();
	Re2=createRect();
	printf("\nRe1 after creation\n");
	printRect(Re1);
	printf("\nRe2 after creation\n");
	printRect(Re2);

	/* get data from user */
	Re1=getData(Re1);
	Re2=getData(Re2);
	printf("\nRe1 after getData\n");
	printRect(Re1);
	printf("\nRe2 after getData\n");
	printRect(Re2);

	/* isSquare */
	if(isSquare(Re1))
		printf("\nThe Rectangle R1 is SQUARE\n");
	else
		printf("\nThe Rectangle R1 is NOT SQUARE\n");

	/* isEqual */
	if(isEqual(Re1,Re2))
		printf("\nThe Rectangle R1 is EQUAL to R2\n");
	else
		printf("\nThe Rectangle R1 is NOT EQUAL to R2\n");

	/* compute Area */
	printf("\nThe Area of Rectangle R1 is %d\n",computeArea(Re1));

	/* Copy Re1 to Re3 */
	Re3=Re1;
	printf("\nRe1 details\n");
	printRect(Re1);
	printf("\nRe3 details after copying Re1\n");
	printRect(Re3);

/* Create RA */
	printf("Enter the Number of Elements in Rect Array\n");
	scanf("%d",&N);
	for(i=0;i<N;i++)
		RA[i]=createRect();
	
/* get data */
	for(i=0;i<N;i++)
		RA[i]=getData(RA[i]);
/* Find the Rectangle with Max Area */
	i=findMaxArea(RA,N);
	printf("\nMax Area Rect is in %d position, its length is %d and its width is %d\n",i,RA[i].length,RA[i].width);
	return 0;
}
