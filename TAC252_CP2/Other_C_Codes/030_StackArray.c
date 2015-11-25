/*
This program introduces the basic concept of stack and the operations 
performed on it. i.e., PUSH and POP.


A stack is a data structure, to store some data.  However, it is not
possible to insert or delete the objects at a random location just like
in the linked lists.

In case of stack, insertions and deletions are possible only at the end.



consider this example:


        1                    2                         3                    4                    5 
     |     |              |     |                   |     |              |     |              |     |
     |     |              |     |                   |     |              |     |              |     |
     |     |              |     |                   |     |              |     |              |     |
     |     |              |     |                   |     |              |     |              |     |
     |     |              |     |                   |     |              |     |              |     |
     |     |              |     |                   | 20  |              |     |              | 30  |
     |     |              | 10  |                   | 10  |              | 10  |              | 10  |
     +-----+              +-----+                   +-----+              +-----+              +-----+
      empty               push 10                   push 20                pop                push 30
     
*/

# include <stdio.h>

# define stackSize 10

int arrayStack[stackSize];

int stackTop = 0;

void Display()
{
    int value;
    printf("The stack contents are...\n");
    printf("*********\n");
    
    for(value = 0; value < stackTop; value++)
        printf("%d\n", arrayStack[value]);

    printf("*********\n");
}

void Push(int value)
{
    if(stackTop == (stackSize - 1))
    {
        printf("Stack size is less.  Stack overflow\n");
        return;
    }
    arrayStack[stackTop++] = value;
    printf("%d is pushed into the stack.  The stack size is...%d\n", value, stackTop);
    Display();
}


int Pop()
{
    if(--stackTop < 0)
    {
        printf("No more elements left in the stack.  Stack underflow\n");
        return;
    }
    
    printf("%d is popped from the stack.  The stack size is...%d\n", arrayStack[stackTop], stackTop);
    Display();
    
    return arrayStack[stackTop];    
}


void main()
{
    int value;
    
    for(value = 10; value < 150; value+= 10) Push(value);
    
    Pop();
    value = Pop();
    
    for(value = 0; value < 9; value++) Pop();
}
