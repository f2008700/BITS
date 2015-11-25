/*     
Program to implement insertion sort algorithm.


Introduction:

In insertion sort, the main idea is to maintain a sorted sublist.
/////////////////////////////////////////////////////////////////////////////////////
EXAMPLE:
consider a list .... { 3, 5, 2, 6}
Let's see the method to sort this list using insertion sort method
/////////////////////////////////////////////////////////////////////////////////////


{ 3, 5, 2, 6}

Consider the least possible subset (from left to right)

____
{ 3, 5, 2, 6}

Since the subtest has only one element, it is already sorted.


Now, let's increase the subset's size to two.
_______
{ 3, 5, 2, 6}


Let's sort this subset.  (It is already sorted; thank you good luck)
_______
{ 3, 5, 2, 6}


Now, let's increase the subset's size to three.
__________
{ 3, 5, 2, 6}


Let's sort this subset.
__________
{ 3, 5, 2, 6}

            Note that the first two are already sorted
             ____  
            {3, 5, 2}

            We simply move the new element (2) to the appropriate position

            1. Take a backup
               
            {3, 5, 2} (2)
           
            2. Compare the adjacent values, starting from right; and move the 
               greater values to wards right
                *      *                               x-->
            {3, 5, 2} (2)    ->  (2 < 5) : YES ->  {3, 5, 5}

             *         *                            x-->
            {3, 5, 5} (2)    ->  (2 < 3) : YES ->  {3, 3, 5}
             
            When no more values are left, copy the backup 
            at the left most greater value's location

             <---------x
            {2, 3, 5} (2)


Now, let's increase the subset's size to four.
_____________
{ 2, 3, 5, 6}


Let's sort this subset.
____________
{ 2, 3, 5, 6}

            Note that the first three are already sorted
             _______  
            {3, 5, 2, 6}

            We simply move the new element (6) to the appropriate position

            1. Take a backup
               
            {2, 3, 5, 6} (6)
           
            2. Compare the adjacent values, starting from right; and move the 
               greater values to wards right
                    *     *
            {2, 3, 5, 6} (6)    ->  (6 < 5) : NO

                *         *
            {2, 3, 5, 6} (6)    ->  (6 < 3) : NO

             *            *
            {2, 3, 5, 6} (6)    ->  (6 < 2) : NO


We have the sorted list ready.... { 2, 3, 5, 6}

*/

# include <stdio.h>


void InsertionSort(int *array, int count)
{
    int loop1, loop2;
    int backupValue;

    for(loop1 = 1; loop1 < count; loop1++)
    {
        backupValue = array[loop1];
        for(loop2 = loop1 - 1; loop2 >= 0; loop2--)
        {
            if(backupValue < array[loop2])
                array[loop2 + 1] = array[loop2];
            //else break;   //uncomment this line for faster code
        }
        array[loop2 + 1] = backupValue;
    }

}


void main()
{
    int a[] = { 9, 4, 2, 1, 9, 2, 1, 0, 3, 4, 5, 8, 7, 6};
    int loop = 0;
    int count = sizeof(a)/sizeof(a[0]);

    printf("\n B4 sort......\n");
    for(loop = 0; loop < count; loop++) printf(" %d", a[loop]);

    InsertionSort(a, count);

    printf("\n After sort......\n");
    for(loop = 0; loop < count; loop++) printf(" %d", a[loop]);
    printf("\n");
}
