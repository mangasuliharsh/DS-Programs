#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

struct queue 
{
    int cqueue[MAX];
    int front,rear;
};
typedef struct queue s1;

void enqueue(s1 *p,int data)
{
    if( (p->rear+1)%MAX == p->front)
    {
        printf("Queue is Full");
    }
    
    else if(p->front == -1 && p->rear == -1)
    {
        p->front=p->rear=0;
        p->cqueue[p->rear] = data;
    }
    else
    {
        p->rear=(p->rear+1)%MAX;
        p->cqueue[p->rear] = data;
    }
}

int dqueue(s1 *p)
{
    if(p->front == -1 && p->rear == -1)
    {
        printf("Queue is Empty");
    }
    else if(p->front == p->rear)
    {
        printf("Dequeued Element : %d",p->cqueue[p->front]);
        p->front=p->rear=-1;
    }
    else
    {
        printf("Dequeued Element : %d",p->cqueue[p->front]);
        p->front=(p->front+1)%MAX;
    }
}

void display(s1 *p)
{
    int i = p->front;
    if(p->front == -1 && p->rear == -1)
    {
        printf("Queue is Empty");
    }
    else
    {   
        printf("Elements in Queue are : ");
        while(i != p->rear)
        {
            printf(" %d ",p->cqueue[i]);
            i = (i+1) % MAX;
        }
        printf(" %d ",p->cqueue[p->rear]);
    }
}

int main()
{
    s1 st;
    st.rear=-1;
    st.front=-1;
    int item,data;
    int choice;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit");
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the Element to be Inserted: ");
                scanf("%d",&item);
                enqueue(&st,item);
            break;

            case 2:
                dqueue(&st);
            break;

            case 3:
                display(&st);
            break;

            case 4:
                exit(1);
            break;

            default:
                printf("Invalid Choice");
            break;
        }
    }
    return 0;
}