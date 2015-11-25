/*
This program is to viusalize the "Towers of Hanoi" problem.

PROBLEM INITIAL STATE:

    |        |        |    
    *        |        |	 
   ***	     |        |	 
  *****	     |        |	 
~~~~~~~~~~~~~~~~~~~~~~~~~~

1. There will be three towers
2. There will be few discs in the first bar
3. These discs will be arranged in ascending order.
4. The 2nd and 3rd towers will not have any discs.

PROBLEM SOLUTION STATE:
The solution for this problem is to move the discs one by one
and to get this final state....

    |       |       |   
    |       |	    *	   
    |       |      ***	   
    |       |     *****	  
~~~~~~~~~~~~~~~~~~~~~~~~~~



RULES:
1. Only one disc should be moved at a time.
2. The disc should be placed only on the towers.
3. A heavier disc should not be placed on a lighter disc.


EXAMPLE:

STEP 0:
    |        |        |    
    *        |        |	 
   ***	     |        |	 
  *****	     |        |	 
~~~~~~~~~~~~~~~~~~~~~~~~~~

STEP 1:
    |        |        | 
    |        |        |	 	 
   ***	     |        |	 
  *****	     |        *	 
~~~~~~~~~~~~~~~~~~~~~~~~~~
STEP 2:
    |        |        |
    |        |        |	 	 
    | 	     |        |	 
  *****	    ***       *  
~~~~~~~~~~~~~~~~~~~~~~~~~~
STEP 3:
    |        |        |
    |        |        |	 
    | 	     *        |	 
  *****	    ***       |	 
~~~~~~~~~~~~~~~~~~~~~~~~~~
STEP 4:
    |        |        |
    |        |        |	 
    | 	     *        |	 
    |	    ***     *****
~~~~~~~~~~~~~~~~~~~~~~~~~~
STEP 5:
    |        |        |
    |        |        |	 
    | 	     |        |	 
    *  	    ***     ***** 
~~~~~~~~~~~~~~~~~~~~~~~~~~
STEP 6:
    |        |        |
    |        |        |	 
    | 	     |       *** 
    *  	     |      *****
~~~~~~~~~~~~~~~~~~~~~~~~~~
STEP 7:
    |        |        |   
    |        |	      *	   
    |        |       ***	   
    |        |      *****	 
~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

# include <stdio.h>
# include <conio.h>

void DisplayDisc(int count, int discs)
{
	int i;
	if(count == -1)
	{
		for(i = 1; i < discs; i++) printf(" ");
		printf("|");
		for(i = 0; i < discs; i++) printf(" ");
		return;
	}

	for(i = 0; i < (discs-count); i++) printf(" ");
	for(i = 0; i < (2*count - 1); i++) printf("*");
	for(i = 0; i <= (discs-count); i++) printf(" ");
}

void DisplayTowers(int towerA[10], int towerB[10], int towerC[10], int discs)
{
	int i;

	for(i = discs - 1; i >= 0; i--)
	{
		DisplayDisc(towerA[i], discs);
		DisplayDisc(towerB[i], discs);
		DisplayDisc(towerC[i], discs);

		printf("\n");
	}
	printf("\nPress any key for the next step....");
	_getch();
	printf("\n\n\n");
}


void InitializeTowers(int towerA[10], int towerB[10], int towerC[10], int discs)
{
	int i;
	for(i = 0; i < discs; i++)
	{
		towerA[i] = discs - i;
		towerB[i] = -1;
		towerC[i] = -1;
	}
	
}


void LegalMove(int t1[10], int t2[10], int *t1Size, int *t2Size)
{
	int index1 = *t1Size;
	int index2 = *t2Size;

	int flag = 0;

	if(index1 == -1) flag = 0;
	else if(index2 == -1) flag = 1;
	else if(t1[index1] < t2[index2]) flag = 1;

	if(flag)
	{
		t2[++index2] = t1[index1];
		t1[index1--] = -1;

		*t2Size = index2;
		*t1Size = index1;
	}
	else
	{
		t1[++index1] = t2[index2];
		t2[index2--] = -1;

		*t2Size = index2;
		*t1Size = index1;
	}
}

void main()
{
	//We have 3 towers.. towerA, towerB, towerC
	int towerA[10];
	int towerB[10];
	int towerC[10];

	//These sizes represent the no. of discs in the each tower
	int aSize, bSize, cSize;

	//The total no. of discs we are playing with
	int discs = 0;  

	printf("Enter a no. less than 10...");
	scanf_s("%d", &discs);
	InitializeTowers(towerA, towerB, towerC, discs);
	DisplayTowers(towerA, towerB, towerC, discs);
	
	aSize = discs - 1;
	bSize = -1;
	cSize = -1;

		
	if(discs % 2)
	{	
		while(1)
		{
			LegalMove(towerA, towerC, &aSize, &cSize);
			DisplayTowers(towerA, towerB, towerC, discs);
			if(towerC[discs-1] != -1) break;

			LegalMove(towerA, towerB, &aSize, &bSize);
			DisplayTowers(towerA, towerB, towerC, discs);
			if(towerC[discs-1] != -1) break;

			LegalMove(towerB, towerC, &bSize, &cSize);
			DisplayTowers(towerA, towerB, towerC, discs);
			if(towerC[discs-1] != -1) break;
		}
	}
	else
	{
		while(1)
		{
			LegalMove(towerA, towerB, &aSize, &bSize);
			DisplayTowers(towerA, towerB, towerC, discs);
			if(towerC[discs-1] != -1) break;

			LegalMove(towerA, towerC, &aSize, &cSize);
			DisplayTowers(towerA, towerB, towerC, discs);
			if(towerC[discs-1] != -1) break;

			LegalMove(towerB, towerC, &bSize, &cSize);
			DisplayTowers(towerA, towerB, towerC, discs);
			if(towerC[discs-1] != -1) break;
		}
	}

}


/*

Exercise:

Implement the towers of hanoi using recursion

*/