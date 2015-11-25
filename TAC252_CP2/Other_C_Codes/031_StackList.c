/*
This program introduces the basic concept of stack and the operations 
performed on it. i.e., PUSH and POP with the help of a linked list.   
*/

# include <stdio.h>
# include <malloc.h>


struct Node
{
    int value;
    struct Node* next;
};

struct Node* stackTop = NULL;


void DisplayStack()
{   
    struct Node *item = stackTop; 
    printf("The contents of the stack are..\n**********\n");
    while(item)
    {
        printf("%d\n", item->value);
        item = item->next;       
    } 
    printf("*********\n");   
}



void Push(int value)
{
    //In the real world applicaitons, make sure that newNode is not null
    //as a result of less available memory
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->next = stackTop;
    stackTop = newNode;
    
    printf("%d is pushed into the stack.\n", value);
    DisplayStack();
}


int Pop()
{
    struct Node* item;
    int value;
    
    if(!stackTop)
    {
        printf("No more elements left in the stack.  Stack underflow\n");
        return;
    }
    
    item = stackTop->next;
    value = stackTop->value;    
    free(stackTop);
    stackTop = item;
    
    printf("%d is popped from the stack.\n", value);
    DisplayStack();   
        
    return value;    
}


void main()
{
    int value;
    
    for(value = 10; value < 150; value+= 10) Push(value);
    
    value = Pop();
    Pop();
    Push(value);
    
    for(value = 0; value < 4; value++) Pop();
    
    //The next line makes sure that we are releasing the memory allocated 
    //for the stack.
    while(stackTop) Pop();
}
