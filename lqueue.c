#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int front = -1;
int rear = -1;
int lqueue[MAX];

void enqueue(int data)
{
    if ( rear == MAX -1)
    {
        printf("Queue is Full");
    }

    else if(front == -1 && rear == -1)
    {
        front=rear=0;
        lqueue[rear] = data;
    }
    else
    {
        rear++;
        lqueue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else if(front == rear)
    {
        printf("Dequeued Element is: %d ",lqueue[front]);
        front=rear=-1;
    }
    else
    {
        printf("Dequeued Element is: %d ",lqueue[front]);
        front++;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Elements in the Queue are: ");
        for(int i=front; i<=rear;i++)
        {
            printf(" %d ",lqueue[i]);
        }
    }
}
int main()
{
    int item , choice ;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
        printf("Please Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Please Enter the element to be inserted: \n");
                scanf("%d",&item);
                enqueue(item);
            break;

            case 2:
                dequeue();
            break;

            case 3:
                display();
            break;

            case 4:
                exit(1);
            break;

            default:
                printf("Invalid Choice!!!\nPlease Enter the Correct Choice");
            break;
        }

    }
}