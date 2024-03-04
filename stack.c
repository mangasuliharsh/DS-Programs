#include <stdio.h>
#include <stdlib.h>
#define MAX 4 
int stack_arr[MAX];
int top = -1 ;

int Overflow()
{
    if(top == MAX - 1)
    return 1;
    else
    return 0;
}

int Underflow()
{
    if(top == -1)
    return 1;
    else
    return 0;
}

void push(int data)
{
    if(Overflow())
    {
        printf("Stack is Full");
        exit(1);
    }
    top = top + 1;
    stack_arr[top] = data;

}

int pop()
{
    if (Underflow())
    {
        printf("Stack is Empty");
        exit(1);
    }
    int value;
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek()
{
    if(Underflow())
    {
        printf("Stack is Empty");
        exit(1);
    }
    return stack_arr[top];
}

int display()
{
    if(Underflow())
    {
        printf("Stack is Empty");
        exit(1);
    }
    printf("The elements in Stack are : \n");
        for(int i=top; i>=0 ; i--)
            {
                printf("%d\n",stack_arr[i]);
            }
}

int main()
{
    
    int item;
    int choice;
    int data;
    int i;
        while(1)
        {
            printf("\n1.Push\n2.Pop\n3.To see the top most element\n4.Display all the elements\n5.Quit ");
            printf("\n Enter your Choice: ");
            scanf("%d",&choice); 
            switch(choice)
            {
                case 1:
                    printf("Enter the Elements to be Pushed: ");
                    scanf("%d",&item);
                    push(item);
                break;

                case 2:
                    data = pop();
                    printf("The Poped Element is: %d", data);
                break;

                case 3:
                    printf("The Topmost Element of the Stack is: %d", peek());
                break;

                case 4:
                    display();
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