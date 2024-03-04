#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode(int x)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p == NULL)
    {
        printf("Memory is not Allocated");
        exit(0);
    }
    p->data=x;
    p->link=NULL;
    return p;
}

NODE freenode(NODE x)
{
    free(x);
}

NODE insert_front(int item,NODE root)
{
    NODE temp;
    temp=getnode(item);
    temp->link=root;
    root = temp;
    return root;
}

NODE delete_front(NODE root)
{
    NODE temp;
    if( root == NULL)
    {
        printf("List is Empty");
        return root;
    }
    temp = root;
    root = root->link;
    printf("\nDeleted Element is %d\n",temp->data);
    freenode(temp);
    return root;
}

NODE insert_rear(NODE root,int item)
{
    NODE temp;
    NODE newnode = getnode(item);
    if(root == NULL)
    {
        return newnode;
    }
    temp = root;
    while(temp->link != NULL)
    {
        temp=temp->link;
    }
    temp->link = newnode;
    return root;
}

NODE delete_rear(NODE root)
{
    NODE prev,temp;
    if(root == NULL)
    {
        return root;
    }
    if(root->link == NULL)
    {
        freenode(root);
        return NULL;
    }
    prev = root;
    temp = root;
    while(temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    printf("\nDeleted Element is %d\n",temp->data);
    freenode(temp);
    prev->link = NULL;
    return root;    
}

void display(NODE root)
{
    NODE temp;
    temp = root;
    if(root == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        printf("\nList is :");
        while(temp != NULL)
        {
            printf(" %d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

NODE insert_pos(NODE root,int ele,int pos)
{
    NODE temp,prev;
    int count = 1;
    if(root == NULL || pos == 1)
    {
        root = insert_front(ele,root);
        return root;
    }
    temp = root;
    prev = NULL;
    while(temp->link != NULL)
    {
        if(count == pos)
        break;

        prev = temp;
        temp=temp->link;
        count++;
    }
    NODE newnode = getnode(ele);
    if(count == pos)
    {
        prev->link = newnode;
        newnode->link = temp;
        return root;
    }
    root = insert_rear(root,ele);
    return root;
}

NODE delete_pos(NODE root,int pos)
{
    NODE prev,temp;
    if(root == NULL)
    {
        printf("List is Empty");
        return root;
    }
    if(pos == 1)
    {
        return delete_front(root);
    }
    prev = root;
    temp = root;
    for(int i=1; temp!=NULL && i<(pos-1); i++)
    {
        prev=temp;
        temp = temp->link;
    }
    if(temp == NULL)
    {
        printf("Invalid Position");
        return root;
    }
    printf("Deleted Element is %d\n",temp->data);
    prev->link = temp->link;
    freenode(temp);
    return root;
}

int search(NODE root,int ele)
{
    int pos;
    NODE temp;
    temp = root;
    if(root == NULL)
    {
        return -1;
    }
    pos = 1;
    while(temp != NULL)
    {
        if(temp->data == ele)
        {
            return pos;
        }
        pos++;
        temp=temp->link;
    }
    return -1;
}

void main()
{
    int ch,item,find;
    NODE root = NULL;
    while(1)
    {
        printf("\n1.Insert at front \n2.Insert at Rear \n3.Insert at Position \n4.Delete at Front \n5.Delete at Rear \n6.Delete at Position \n7.Search \n8.Display \n9.Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                root = insert_front(item,root);
            break;

            case 2:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                root = insert_rear(root,item);
            break;

            case 3:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                printf("\nEnter the Position: ");
                scanf("%d",&find);
                root = insert_pos(root,item,find);
            break;

            case 4:
                root = delete_front(root);
            break;

            case 5:
                root = delete_rear(root);
            break;

            case 6:
                printf("\nEnter the Position: ");
                scanf("%d",&find);
                root = delete_pos(root,find);
            break;

            case 7:
                printf("\nEnter the element to  find: ");
                scanf("%d",&item);
                find = search(root,item);
                if(find == -1)
                {
                    printf("\nElement not Found\n");
                }
                else{
                    printf("\n%d is found at %d position\n",item,find);
                }
            break;

            case 8:
                display(root);
            break;

            case 9:
                exit(1);
            break;

            default:
                printf("Invalid Choice");
            break;
        }
    }
}