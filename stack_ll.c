#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE top = NULL;

NODE createstack(int ele)
{
    NODE p;
    p = (NODE)malloc(sizeof(struct node));
    if(p == NULL)
    {
        printf("Memory is not Allocated");
        exit(1);
    }
    p->data = ele;
    p->next = NULL;
    return p;
}

void push(int ele)
{
    NODE newnode = createstack(ele);
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack is Empty");
        return 1;
    }
    NODE temp = top;
    int value = temp->data;
    top = temp->next;
    free(temp);
    return value;
}

void display()
{
    if(top == NULL)
    {
        printf("Stack is Empty");
        return ;
    }
    else{
        NODE temp = top;
        printf("Stack is:\n");
        while(temp != NULL)
        {   
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int chk,item;
    int value;
    while(1)
    {
        printf("\n---------------WELCOME TO THE MENU---------------");
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
        printf("\nEnter your Choice?\n");
        scanf("%d",&chk);
        switch(chk)
        {
            case 1:
                printf("Enter the Element: ");
                scanf("%d",&item);
                push(item);
            break;

            case 2:
                value = pop();
                printf("Popped Element is: %d",value);
            break;

            case 3:
                display();
            break;

            case 4:
                exit(1);
            break;

            default:
                printf("Invalid Choice");
            break;

        }
    }
}