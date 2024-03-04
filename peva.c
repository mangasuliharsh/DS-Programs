#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define N 100

int top;
double stack[N];

void push(int symbol)
{
    top++;
    stack[top] = symbol;
}

double pop()
{
    int  value;
    value = stack[top];
    top--;
    return value;
}

double cal(char symbol,double op1,double op2)
{
    switch(symbol)
    {
        case '^':
        case '$':return pow(op1,op2);
        case '*':return op1 * op2;
        case '/':return op1 / op2;
        case '+':return op1 + op2;
        case '-':return op1 - op2;
    }
}

double evaluation(char postfix[])
{
    double op1,op2,res;
    char symbol;
    int i = 0;
    while(postfix[i]!='\0')
    {
        symbol = postfix[i++];
        if(isdigit(symbol))
        {
            push(symbol-'0');
        }
        else
        {
            op2=pop();
            op1=pop();
            res = cal(symbol,op1,op2);
            push(res);
        }
    }
    double result = pop();
    return result;
}

int main()
{   
    top = -1;
    double res;
    char postfix[N];
    printf("Enter the Postfix Expression: ");
    scanf("%s",postfix);
    res = evaluation(postfix);
    printf("Evaluated Postfix Expression: %f",res);
}
