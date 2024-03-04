#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200 

char stack_arr[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

int space(char c)
{
    if(c == ' ' ||  c == '\t')
    {
        return 1;
    }
    else
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    return 0;
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void push(char data)
{
    if (top == MAX -1)
    {
        printf("Stack is Full");
        exit(1);
    }
    top = top + 1;
    stack_arr[top] = data;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is Empty");
        exit(1);
    }
    char value;
    value = stack_arr[top];
    top = top - 1;
    return value;
}

void intoPost()
{
    int i, j = 0;
    char next;
    char symbol;
    for(i = 0; i < strlen(infix); i++)
    {
        symbol=infix[i];
        if(!space(symbol))

        {
            switch(symbol)
            {
                case '(':
                    push(symbol);
                break;

                case ')':
                    while((next=pop()) != '(')
                    postfix[j++] = next ;
                break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty() && precedence(stack_arr[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                    push(symbol);
                    break;

                default:
                    postfix[j++] = symbol ;
                break;

            }
        }
    } 
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
        
}

void print()
{
    int i = 0;
    printf("The Equivalent Postfix Expression is: ");
    while(postfix[i]){
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the Infix Expression: ");
    gets(infix);
    intoPost();
    print();
    return 0;
}
