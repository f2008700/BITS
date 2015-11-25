/*
Program to implement bubble sort algorithm.


Introduction:
Sorting is a process of arranging a list in an order.
sorting of lists is very useful in search process.
There are many kinds of sorting algorithms.

Bubble sort is one of the simplest algorithms.

We will start comparing pair wise and will swap them.
We will stop when no swaps occured or no pairs are left to compare

EXAMPLE:

consider a list : 

10
40
30
20
60
///////////////////////////////////////////////////
STEP 1:

10\
   \
    |*** compare (10 < 40) true .. so no swapping
   /
40/

30

20

60
///////////////////////////////////////////////////
STEP 2:

10

40\
   \
    |*** compare (40 < 30) false .. so swap them
   /
30/

20

60
///////////////////////////////////////////////////
STEP 3:

10

30

40\
   \
    |*** compare (40 < 20) false .. so swap them
   /
20/

60

///////////////////////////////////////////////////
STEP 4:

10

30

20

40\
   \
    |*** compare (40 < 60) true .. so no swapping
   /
60/

///////////////////////////////////////////////////
STEP 5:

10\
   \
    |*** compare (10 < 30) true .. so no swapping
   /
30/

20

40

60

///////////////////////////////////////////////////
STEP 6:

10

30\
   \
    |*** compare (30 < 20) false .. so swap them
   /
20/

40

60

///////////////////////////////////////////////////
STEP 7:

10

20

30\
   \
    |*** compare (30 < 40) true .. so no swapping
   /
40/

60

///////////////////////////////////////////////////
STEP 8:

10

20

30

40\
   \
    |*** compare (40 < 60) true .. so no swapping
   /
60/


*/

# include <stdio.h>

void main()
{
    int values[10] = { 10, 40, 20, 90, 80, 60, 30, 70, 50, 100 };
    int loop;
    int swapped = 1;
    
    printf("The list before sorting is....\n");
    for(loop = 0; loop < 10; loop++) printf("%d\n", values[loop]);
    
    while(swapped)
    {
        swapped = 0;
        
        for(loop = 1; loop < 10; loop++)
        {
            if(values[loop] < values[loop-1])
            {
                int temp = values[loop];
                values[loop] = values[loop-1];
                values[loop-1] = temp;
                
                swapped = 1;
            }
        }
    }
    
    printf("The list after sorting is....\n");
    for(loop = 0; loop < 10; loop++) printf("%d\n", values[loop]);    
    
}
