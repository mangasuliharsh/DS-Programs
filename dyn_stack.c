#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct stack {
    int *array;
    int top;
    int maxsize;
};

typedef struct stack ST;

ST* createStack(int n)
{
    ST* ptr;
    ptr = (ST*)malloc(sizeof(struct stack));
    if(ptr == NULL)
    {
        printf("Memory not Allocated");
    }
    ptr->top=-1;
    ptr->maxsize=n;
    ptr->array=(int*)malloc(ptr->maxsize*sizeof(int));
    return ptr;

}

int overflow(ST *p)
{
    if(p->top == p->maxsize-1)
    {
        return 0;
    }
    else{
        return 1;
    }
}

int underflow(ST *p)
{
    if(p->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void push(ST *p,int item)
{
    ST s1;
    if(overflow(&s1))
    {
        printf("Stack is Full");
    }
    else
    {
        p->array[p->top]=item;
        p->top++;
    }
}

int pop(ST *p)
{
    ST s1;
    int value;
    if(underflow(&s1))
    {
        printf("Stack is Empty");
    }
    else
    {
        value = p->array[p->top];
        p->top--;
        return value;
    }
}

int peek(ST *p)
{
    ST s1;
     int value;
    if(underflow(&s1))
    {
        printf("Stack is Empty");
    }
    value = p->array[p->top];
    return value;
}

void display(ST *p)
{
    ST s1;
    if(underflow(&s1))
    {
        printf("Stack is Empty");
    }
    printf("Stack is :");
    int i;
    for(i = p->top; i>=0 ; i--)
    {
        printf("\n%d",p->array[i]);
    }
}

int main()
{
    int item,ch;
    ST* s1;
    int size,value;
    printf("\nEnter the Number  of Elements you want Push: ");
    scanf("%d",&size);
    s1 = createStack(size);
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("Enter the Element you want to push: ");
                scanf("%d",&item);
                push(&s1,item);
            break;

            case 2:
                value = pop(&s1);
                printf("%d is Popped",value);
            break;
            
            case 3:
                value = peek(&s1);
                printf("%d is at Top",value);
            break;

            case 4:
                display(&s1);
            break;

            case 5:
                exit(1);
            break;
        }

    }
}