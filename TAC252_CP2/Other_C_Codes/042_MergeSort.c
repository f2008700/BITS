/*
Program to implement merge sort algorithm.


Introduction:

In merge sort, the main idea is to divide the given list into two parts;
sort each of these parts, and then merge them.

So, let's see the method how to merge two already sorted arrays

/////////////////////////////////////////////////////////////////////////////////////
EXAMPLE:    consider two lists :       {20, 30, 40},  {10, 50, 70}
/////////////////////////////////////////////////////////////////////////////////////

STEP 1:
Initially, the merged values list will be empty

LEFT VALUES         RIGHT VALUES     MERGED VALUES:
{20, 30, 40}        {10, 50, 70}          { }


STEP 2:
Append all the left values that are less than the right values
into the MERGED VALUES

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}          { }
     *                   *
    (20 < 10) -> NO


STEP 3:
Append all the right values that are less than the left values
into the MERGED VALUES
--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}          { }
     *                   *
    (10 < 20) -> YES - APPEND 10 to MERGED VALUES

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}          {10}
     *                       *
    (50 < 20) -> NO

STEP 4:
Append all the left values that are less than the right values
into the MERGED VALUES

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}        {10}
     *                       *
    (20 < 50) -> YES - APPEND 20 to MERGED VALUES

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}       {10, 20}
         *                   *
    (30 < 50) -> YES - APPEND 30 to MERGED VALUES

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}      {10, 20, 30}
             *               *
    (40 < 50) -> YES - APPEND 40 to MERGED VALUES

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}    {10, 20, 30, 40}
              -              *

STEP 5:
We have nothing left in the left side values. So, we can simply add all the 
remaining right values to the MERGED VALUES.
--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}    {10, 20, 30, 40}
              -              *

--> LEFT VALUES         RIGHT VALUES     MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}  {10, 20, 30, 40, 50}
              -                  *

--> LEFT VALUES         RIGHT VALUES       MERGED VALUES:
    {20, 30, 40}        {10, 50, 70}  {10, 20, 30, 40, 50, 70}
               -                   -


That's how we get the sorted array at the end.
*/

# include <stdio.h>
# include <malloc.h>

void Merge(int *left, int leftSize, int *right, int rightSize, int *array)
{
    int offset = 0;
    int loop1 = 0, loop2 = 0;
    int count = leftSize + rightSize;
 
    while(offset < count)
    {
        while(left[loop1] <= right[loop2])
        {
            array[offset++] = left[loop1++];        
            if(loop1 == leftSize)
            {
                while(loop2 < rightSize) array[offset++] = right[loop2++];
                return;
            }
        }
        while(right[loop2] <= left[loop1])
        {
            array[offset++] = right[loop2++];
            if(loop2 == rightSize)
            {
                while(loop1 < leftSize) array[offset++] = left[loop1++];
                return;
            }
        }
    }
}


void MergeSort(int *array, int count)
{
    int *leftValues = 0;
    int *rightValues = 0;
    int *values = 0;
    int loop = 0;
    int leftSize, rightSize;

    if(count < 2) return;

    values = (int*)malloc(count*sizeof(int));
    for(loop = 0; loop < count; loop++) values[loop] = array[loop];

    leftValues = values;
    leftSize = count/2;

    rightValues = values + leftSize;
    rightSize = count - leftSize;

    MergeSort(leftValues, leftSize);
    MergeSort(rightValues, rightSize);

    Merge(leftValues, leftSize, rightValues, rightSize, array);

    free(values);
}


void main()
{
    int a[] = { 9, 4, 2, 1, 9, 2, 1, 0, 3, 4, 5, 8, 7, 6};
    int loop = 0;
    int count = sizeof(a)/sizeof(a[0]);

    printf("\n B4 sort......");
    for(loop = 0; loop < count; loop++) printf(" %d", a[loop]);

    MergeSort(a, count);

    printf("\n After sort......");
    for(loop = 0; loop < count; loop++) printf(" %d", a[loop]);
    printf("\n");
}
