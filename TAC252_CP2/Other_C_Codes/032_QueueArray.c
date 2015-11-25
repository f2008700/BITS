/*
This program introduces the basic concept of queue and the operations 
performed on it. i.e., INSERT and REMOVE


A queue is a data structure, to store some data.  However, it is not
possible to insert or remove the objects at a random location just like
in the linked lists.

In case of queue, insertions are possible only at the beginning.
and the removals are possible only at the ending.



consider this example:

empty queue:
        +-----+-----+-----+-----+-----+-----+
        |     |     |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+    
        
insert 10:
        +-----+-----+-----+-----+-----+-----+
        | 10  |     |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+ 
        
insert 20:
        +-----+-----+-----+-----+-----+-----+
        | 10  | 20  |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+ 
        
remove
        +-----+-----+-----+-----+-----+-----+
        | 20  |     |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+ 
        
insert 30:
        +-----+-----+-----+-----+-----+-----+
        | 20  | 30  |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+ 
        
remove
        +-----+-----+-----+-----+-----+-----+
        | 30  |     |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+ 
        
        
remove
        +-----+-----+-----+-----+-----+-----+
        |     |     |     |     |     |     |
        +-----+-----+-----+-----+-----+-----+  
*/

# include <stdio.h>

# define queueSize 10

int arrayQueue[queueSize];

int queueEnd = 0;

void Display()
{
    int value;
    printf("The queue contents are...\n");
    printf("*********\n");
    
    for(value = 0; value < queueEnd; value++)
        printf("%d\n", arrayQueue[value]);

    printf("*********\n");
}

void Insert(int value)
{
    if(queueEnd == (queueSize - 1))
    {
        printf("Queue size is less.  Queue overflow\n");
        return;
    }
    arrayQueue[queueEnd++] = value;
    printf("%d is inserted into the queue.  The queue size is...%d\n", value, queueEnd);
    Display();
}


int Remove()
{
    int loop;
    int value;
    if(queueEnd <= 0)
    {
        printf("No more elements left in the queue.  queue underflow\n");
        return;
    }
    
    value = arrayQueue[0];
    printf("%d is removed from the queue.  The queue size is...%d\n", value, --queueEnd);
    
    //Move all the elements in the queue one position towards the queue beginning
    for(loop = 1; loop <= queueEnd; loop++) arrayQueue[loop-1] = arrayQueue[loop];
    Display();
    
    return value;    
}


void main()
{
    int value;
    
    for(value = 10; value < 150; value+= 10) Insert(value);
    
    Remove();
    value = Remove();
    
    for(value = 0; value < 9; value++) Remove();
}
