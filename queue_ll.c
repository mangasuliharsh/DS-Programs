#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE front = NULL;
NODE rear = NULL;

NODE create(int ele)
{
    NODE p;
    p = (NODE)malloc(sizeof(struct node));
    if(p == NULL)
    {
        printf("Memory not Allocated");
        exit(1);
    }
    p->data = ele;
    p->next = NULL;
    return p;
}

void enqueue(int ele)
{
    NODE newnode = create(ele);
    if(rear == NULL && front == NULL)
    {
        rear = front = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    if(rear == NULL)
    {
        printf("Queue is Empty");
        return -1;
    }
    NODE temp = front;
    front = front->next;
    int value = temp->data;
    if(front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return value;
}

void display()
{
    if(rear == NULL)
    {
        printf("Queue is Empty");
        return;
    }
    else
    {
        NODE temp = front;
        printf("Queue is: ");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
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
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
        printf("\nEnter your Choice?\n");
        scanf("%d",&chk);
        switch(chk)
        {
            case 1:
                printf("Enter the Element: ");
                scanf("%d",&item);
                enqueue(item);
            break;

            case 2:
                value = dequeue();
                printf("Dequeued Element is: %d",value);
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