//WAP to convert an infix expression to postfix expression
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
class InfixToPostfix
{
    char X[50],stack[50];
    int top;
    public:
    InfixToPostfix();
    void readExpression();
    void convert();
    char pop();
    void push(char);
    int checkPrecedence(char);
};

InfixToPostfix::InfixToPostfix()
{
    top=-1;
    X[0]='\0';
    stack[0]='\0';
}


void InfixToPostfix::readExpression()
{
    gets(X);
}


void InfixToPostfix::convert()
{
    char Y[50],val;
    int l=strlen(X),len=0,pr,pr1;
    push('(');
    X[l]=')';
    for(int i=0;i<=l;i++)
    {
        if(isalnum(X[i]))
        {
            Y[len]=X[i];
            len++;
        }
        else if(X[i]=='(')
            push(X[i]);
        else if(X[i]=='^'||X[i]=='/'||X[i]=='*'||X[i]=='+'||X[i]=='-')
        {
            pr=checkPrecedence(X[i]);
            pr1=checkPrecedence(stack[top]);
            while(pr1>pr||pr1==pr)
            {
                val=pop();
                Y[len]=val;
                len++;
                pr1=checkPrecedence(stack[top]);
            }
            push(X[i]);
        }
        else if(X[i]==')')
        {
            while(stack[top]!='(')
            {
                val=pop();
                Y[len]=val;
                len++;
            }
            pop();
        }
    }
    Y[len]='\0';
    cout<<Y;
}
char InfixToPostfix::pop()
{
    char val=stack[top];
    top--;
    return val;
}
void InfixToPostfix::push(char val)
{
    top++;
    stack[top]=val;
}
int InfixToPostfix::checkPrecedence(char op)
{
    int prior;
    if(op=='^')
        prior=3;
    else if(op=='/'||op=='*')
        prior=2;
    else if(op=='+'||op=='-')
        prior=1;
    return prior;
}
void main()
{
    clrscr();
    InfixToPostfix ob;
    cout<<"Enter any infix expression"<<endl;
    ob.readExpression();
    ob.convert();
    getch();
}
