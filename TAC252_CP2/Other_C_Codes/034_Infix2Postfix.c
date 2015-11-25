/*

This program converts an infix expression to postfix expression

example:

infix expresssion :   a + b
postfix expression:   a b +

infix is an expression, where the operator is placed in between the operands
in postfix expression, the opertor is placed after the two operands


complex expressions:

It is possible to have two or more expressions to be combined.

example: a + b * ( c - d )

It is same as....

--> a + { b * (c d -) }
--> a + { b (c d -) * }
--> a + ( b c d - *) 
--> a b c d - * +


Priority in operands:

consider the expression "a + b * c"

even though + is the first operator in the expression, * operation should be done first
as * has higher priority.

so, the expression's postfix form is ....... a b c * +

*/

# include <stdio.h>
# include <stdlib.h>

char stack[100];
int stackTop = 0;

void Push(char operator)
{
    stack[stackTop++] = operator;
}


char Pop()
{
    return stack[--stackTop];
}


int Priority(char operator)
{
    if(operator == '+') return 1;
    if(operator == '-') return 1;
    
    if(operator == '/') return 2;
    if(operator == 'x') return 2;
    if(operator == 'X') return 2;
    if(operator == '%') return 2;
    
    if(operator == '[') return 3;
    if(operator == ']') return 0;
    
    return -1;
}


int CurrentOperatorPriority()
{
    char operator;
    if(stackTop <= 0) return -1;
    if(stack[stackTop-1] == '[') return -1;
    
    return Priority(stack[stackTop-1]);   
}


int IsNumber(char element)
{
    if(element >= '0' && element <= '9') return 1;
    return 0;
}


void PopAllOperators()
{    
    while(stackTop)
    {  
        char operator = Pop();
        if(operator == '[') break;
        printf("%c ", operator);  
    }   
}

void Parse(char* token)
{
    char operator;

    if(IsNumber(token[0]))
    {
        printf("%s ", token);
        return;
    }
    
    if(token[0] == ']' )
    {
        PopAllOperators();       
        return;
    }
    
    if( CurrentOperatorPriority() < Priority(token[0]) )
    {
        Push(token[0]);
        return;
    }
    
    PopAllOperators();
    Push(token[0]);
    
}

//eg. usage: ./a.out 89 + 98 x 34 - [ 45 / [ 3 + 2 ] ]
//make sure that you use spaces between the operators and numbers
//and use x instead of *

void main(int count, char** arguments)
{
    int loop;
    
    for(loop = 1; loop < count; loop++) Parse(arguments[loop]);   
    
    PopAllOperators();
    printf("\n");
}
