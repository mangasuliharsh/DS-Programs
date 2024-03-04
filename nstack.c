#include <stdio.h>
#include <stdlib.h>
#define max 10
struct STACK {
    int top;
    int array[max];
    
};

typedef struct STACK st;

void push(st *p,int item)
{
    if(p->top == max -1 )
    {
        printf("Stack is empty");
    }
    p->top++;
    p->array[p->top]=item;
    return;
}

int pop(st *p)
{
    int value;
    if(p->top == -1)
    {
        printf("Stack is empty");
    }
    value = p->array[p->top];
    p->top--;
    return value;
}

int peek(st *p)
{
    if(p->top == -1)
    {
        printf("Stack is empty");
    }
    return p->array[p->top];
}

void display(st *p)
{
    if(p->top == -1)
    {
        printf("Stack is Empty");
    }
    printf("The Elements in the Stack are: \n");
    for(int i=p->top;i>=0;i--)
    {
        printf("%d\n",p->array[i]);
    }
}

int main()
{   
    st *p;
    st stack;
    stack.top=-1;
    int item;
    int choice;
    int data;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&item);
                push(&stack,item);
            break;

            case 2:
                data = pop(&stack);
                printf("The Element Poped is: %d",data);
            break;

            case 3:
                printf("The Element in the Top is: %d",peek(&stack));
            break;

            case 4:
                display(&stack);
            break;

            case 5:
                exit(1);
            break;

            default:
                printf("Invalid Choice");
            break;

        }
    }
    return 0;

}
