#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode(int x)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Memory Not Allocated");
        exit(0);
    }
    temp->data = x;
    temp->link = temp;
    return temp;
}

NODE insert_front(NODE last, int ele)
{
    NODE newnode = getnode(ele);
    if (last == NULL)
    {
        newnode->link = newnode;
        return newnode;
    }
    NODE first = last->link;
    newnode->link = first;
    last->link = newnode;
    return last;
}


NODE insert_rear(NODE last, int ele)
{
    NODE newnode = getnode(ele);
    if (last == NULL)
    {
        newnode->link = newnode;
        return newnode;
    }
    NODE first = last->link;
    last->link = newnode;
    newnode->link = first;
    return newnode;
}


NODE delete_front(NODE last)
{
    NODE first = last->link;
    if(last == NULL)
    {
        printf("List is Empty\n");
        return last;
    }
    if(last->link == last)
    {
        free(last);
        return NULL;
    }
    last->link = first->link;
    printf("Deleted Element is %d",first->data);
    free(first);
    return last;
}

NODE delete_rear(NODE last)
{
    NODE first = last->link;
    if(last == NULL)
    {
        printf("List is Empty\n");
        return last;
    }
    if(last->link == last)
    {
        free(last);
        return NULL;
    }
    while(first->link != last)
    {
        first = first->link;
    }
    first->link=last->link;
    printf("Deleted Element is %d",last->data);
    free(last);
    return first;
}

void display(NODE last)
{
    NODE first = last->link;
    if(last == NULL)
    {
        printf("List is Empty");
        return;
    }
    else
    {
        printf("List is: ");
        while(first != last)
        {
            printf(" %d",first->data);
            first=first->link;
        }
    }
    printf(" %d",last->data);
}

int main()
{
    NODE last = NULL;
    int item,chk;
    while(1)
    {
        printf("\n---------------WELCOME TO THE MENU---------------");
        printf("\n1.Insert at Front \n2.Insert at Back \n3.Delete at Front \n4.Delete at Back \n5.Display \n6.Exit\n");
        printf("Enter your choice?\n");
        scanf("%d",&chk);
        switch(chk)
        {
            case 1:
                printf("Enter the Element: ");
                scanf("%d",&item);
                last = insert_front(last,item);
            break;

            case 2:
                printf("Enter the Element: ");
                scanf("%d",&item);
                last = insert_rear(last,item);
            break;

            case 3:
                last = delete_front(last);
            break;

            case 4:
                last = delete_rear(last);
            break;

            case 5:
                display(last);
            break;

            case 6:
                exit(0);
            break;

            default:
                printf("Invalid Choice");
            break;
        }
    }
}