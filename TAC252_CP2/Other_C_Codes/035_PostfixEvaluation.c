/*
program to evaluate the given post fix expression
*/

# include <stdio.h>
# include <stdlib.h>


int stack[100];
int stackTop = -1;

void Push(int value)
{
    //stack may overflow.
    //ok for simple examples
    stack[++stackTop] = value;
}


int Pop()
{
    return stack[stackTop--];
}


int GetOperator(char* token)
{
    if(token[0] >= '0' && token[0] <= '9') return 0;
    
    return token[0];
}


int Compute(int value1, int value2, int operator)
{
    int value;
    
    if(operator == 'x' || operator == 'X') value = value1 * value2;
    if(operator == '-') value = value1 - value2;
    if(operator == '+') value = value1 + value2;
    if(operator == '%') value = value1 % value2;
    if(operator == '/') value = value1 / value2;

    printf("%d %c %d = %d\n", value1, operator, value2, value);
    return value;
}


void main(int count, char** arguments)
{
    int loop;
    int operator;
    int value1;
    int value2;
    int value;
    
    for(loop = 1; loop < count; loop++)
    {
        operator = GetOperator(arguments[loop]);
        
        if(operator) 
        {
            value2 = Pop();
            value1 = Pop();
            value = Compute(value1, value2, operator);
            Push(value);
        }
        else
        {
            value = atoi(arguments[loop]);
            Push(value);
        }
    }
    
    printf("The given expression evaluates to....%d\n", value);
    
    
}
