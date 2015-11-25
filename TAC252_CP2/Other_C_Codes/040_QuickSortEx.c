/*
NOTE:
Make sure that you are comfortable with 
EasyQuickSort function in the previous program


RECAP:
EasyQuickSort will create two lists...
1) lesser values list
2) greater values list


SUMMARY:
In this FastQuickSort, we will not create any new lists;
But we will rearrnage the existing array so that
1)the array elements to the left of the pivot are lesser
2)the array elements to the right of the pivot are gerater


EXAMPLE:
if we get a list..............{8, 9, 5, 7, 6, 1, 2} 
                                        ^
Note that 7 is marked as it is the middle element of the list


we re-arrange the list like...{5, 2, 6, 1, 7, 9, 8}
                                           ~
values to the left of 7 are lesser than 7 and
values to the right of 7 are greater than 7


METHOD:

1. Mark the middle element in the array; and call it pivotValue
{8, 9, 5, 7, 6, 1, 2}
          ^

2. we will be comparing the other elements of the array
with the pivotValue to determine what values are lesser.
To do that, first we exchange the pivotValue and the last element
{8, 9, 5, 2, 6, 1, 7}
                   

3.Now, we will count the no. of values, lesser than pivotValue.
First we assume that there are no lesser values and assume that the 
actual pivot position is the left most position.

{8, 9, 5, 2, 6, 1, 7}
 ~

4.And we will check if our assumption is right/wrong.
To do so, we will be comparing the values with pivotValue

 *                 *          
{8, 9, 5, 2, 6, 1, 7}       ->  (8 < 7)  :  NO
 ~

    *              *          
{8, 9, 5, 2, 6, 1, 7}       ->  (9 < 7)  :  NO
 ~

       *           *          
{8, 9, 5, 2, 6, 1, 7}       ->  (5 < 7)  :  YES
 ~                 
        We assumed that there are no lesser values; but we found one.
        So, it's time to update our assumption;
        Exchange the lesser value with the value at the assumed pivot position
        (WHY??? Because, the lesser value comes to the left side)
        And we will increment the actual pivot position by one. 
        (Why?? Because, we just found one lesser value)
         x     x
        {5, 9, 8, 2, 6, 1, 7}
            ~

          *        *          
{8, 9, 5, 2, 6, 1, 7}       ->  (2 < 7)  :  YES
    ~
        It's time to update our assumption;
        Exchange the lesser value with the value at the assumed pivot position
        And we will increment the actual pivot position by one.
            x     x
        {5, 2, 8, 9, 6, 1, 7}
               ~

             *     *          
{5, 2, 8, 9, 6, 1, 7}       ->  (6 < 7)  :  YES
       ~
        It's time to update our assumption;
        Exchange the lesser value with the value at the assumed pivot position
        And we will increment the actual pivot position by one.
               x     x
        {5, 2, 6, 9, 8, 1, 7}
                  ~


                *  *          
{5, 2, 6, 9, 8, 1, 7}       ->  (1 < 7)  :  YES
          ~
        It's time to update our assumption;
        Exchange the lesser value with the value at the assumed pivot position
        And we will increment the actual pivot position by one.
                  x     x
        {5, 2, 6, 1, 8, 9, 7}
                     ~

Now, we have nothing left to compare with the pivotValue.
So, we have no more updations to the assumed pivot position.
It is the actual pivot position.
So, we need to exchange the pivotValue with the value at the actual pivot

             x     x
{5, 2, 6, 1, 7, 9, 8}
             ~

Now, note that the values to the left of the pivot value are lesser
and the values to the right of the pivot are greater


*/




# include <stdio.h>


void Swap(int *array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y]; 
    array[y] = temp;
}


int Partition(int *array, int min, int max)
{
    int assumedPivot = (min + max)/2;
    int pivotValue = array[assumedPivot];

    //We keep on correcting this actualPivot point
    //We start with the assumption that there are no
    //values in the array, that are less than the pivotValue
    //As we come across any lesser value, we do actualPivot++
    int actualPivot = min;

    int loop;

    //We may lose our pivot value after the comparisions.
    //So, we will place the assumed pivot at the last position
    Swap(array, assumedPivot, max);

    //move the first lesser value to the first value in the array
    //move the second lesser value to the second value in the array
    // and so on....
    for(loop = min; loop < max; loop++)
    {
        if(array[loop] <= pivotValue)
        {
            Swap(array, loop, actualPivot++);
        }
    }
    Swap(array, actualPivot, max);
    return actualPivot;
}


void FastQuickSort(int *array, int min, int max)
{
    int pivot;

    if(max <= min) return;

    pivot = Partition(array, min, max);
    FastQuickSort(array, min, pivot - 1);
    FastQuickSort(array, pivot + 1, max);     
}



void main()
{
    int a[] = { 9, 4, 2, 1, 9, 2, 1, 0, 3, 4, 5, 8, 7, 6};
    int loop = 0;
    int count = sizeof(a)/sizeof(a[0]) - 1;

    printf("\n B4 sort......\n");
    for(loop = 0; loop <= count; loop++) printf(" %d", a[loop]);

    FastQuickSort(a, 0, count);

    printf("\n After sort......\n");
    for(loop = 0; loop <= count; loop++) printf(" %d", a[loop]);
    printf("\n");
}
