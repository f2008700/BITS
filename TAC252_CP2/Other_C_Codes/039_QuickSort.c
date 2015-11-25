/*
Program to implement quick sort algorithm.


Introduction:

In quick sort, the main idea is to select an element in the list and to maintain 
only the numbers that are less than the selected no. at the left
and to have only the greater numbers on the right.

/////////////////////////////////////////////////////////////////////////////////////
EXAMPLE:
/////////////////////////////////////////////////////////////////////////////////////
STEP 1:

consider a list : 

                                          90    60    40    30    25    20   10
                                         -------------------^^------------------
(divide the list into two lists)               /            |             \
1. list with lesser values                    /             |              \
2. list with greater values                  /              |               \
                                       25   20  10         30           90  60  40
                                      ------^^-----                    -----^^-----  
(repeat the same for the new lists)          |              |                |
                                             |              |                |
                                             |              |                |             
  The sorted list ------------------>  10   20  25         30            40 60  90



/////////////////////////////////////////////////////////////////////////////////////
STEP 2:

In Step 1, we got 3 items in the lesser values list
and also 3 items in the greater values list.

It is just by luck that we got equal sized lists.
But sometimes we get lists with unequal sizes.

cosider a list

                                          90    60    40    30    25    20   10    5
                                         -------------------^^----------------------
(divide the list into two lists)               /            |             \
1. list with lesser values (4 items)          /             |              \
2. list with greater values (3 items)        /              |               \
                                       25   20  10   5     30           90  60  40
                                      ------^^--------                 -----^^-----  
(repeat the same for the new lists)          |              |                |
                                             |              |                |
                                             |              |                |             
                                     10  5  20  25         30            40 60  90
                                     ^^---   |   |          |            |  |   |
                                             |   |          |            |  |   |
                                             |   |          |            |  |   |
  The sorted list ---------------->  5  10  20  25         30           40 60  90


NOTE:
Observe that "30" was the 4th item in the original list, but....
After dividing the list into two sub lists, it became the 5th item

*/

# include <stdio.h>
# include <malloc.h>


//merges a and b into c
void Merge(int *a, int *b, int *c, int max, int pivot, int pivotValue)
{
    int loop1 = 0, loop2 = 0;

    while(loop1 < pivot) c[loop1++] = a[loop2++];
    c[pivot] = pivotValue;

    loop1 = pivot + 1;
    loop2 = 0;
    while(loop1 < max)  c[loop1++] = b[loop2++];
}


//EasyQuickSort is just to explain how the sort works
//A more difficult and efficient function is explained later
void EasyQuickSort(int *array, int max)
{
    int *lesserValues = 0;
    int lesserValuesCount = 0;

    int *greaterValues = 0;
    int greaterValuesCount = 0;

    int loop = 0;
    int pivot = max/2;
    int pivotValue = 0;

    if(max <= 1) return;

    lesserValues = (int*) malloc( sizeof(int) * max);
    greaterValues = (int*) malloc( sizeof(int) * max);
    pivotValue = array[pivot];

    for(loop = 0; loop < max; loop++)
    {
        if(loop == pivot) continue;

        if(array[loop] <= pivotValue) lesserValues[lesserValuesCount++] = array[loop];
        else greaterValues[greaterValuesCount++] = array[loop];
    }
    EasyQuickSort(greaterValues, greaterValuesCount);
    EasyQuickSort(lesserValues, lesserValuesCount);

    Merge(lesserValues, greaterValues, array, max, lesserValuesCount, pivotValue);

    free(lesserValues);
    free(greaterValues); 
}


void main()
{
    int a[] = { 9, 4, 2, 1, 9, 2, 1, 0, 3, 4, 5, 8, 7, 6};
    int loop = 0;
    int count = sizeof(a)/sizeof(a[0]);

    printf("\n B4 sort......");
    for(loop = 0; loop < count; loop++) printf(" %d", a[loop]);

    EasyQuickSort(a, count);

    printf("\n After sort......");
    for(loop = 0; loop < count; loop++) printf(" %d", a[loop]);
    printf("\n");
}
