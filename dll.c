#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;;
    struct node *right;
    struct node *left;
};

typedef struct node *NODE;

NODE getnode(int x)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p == NULL)
    {
        printf("Memory not Allocated");
        exit(1);
    }
    p->data=x;
    p->right=NULL;
    p->left=NULL;
    return p;
}

NODE insert_front(NODE root,int ele)
{
    NODE newnode = getnode(ele);
    newnode->right = root;
    newnode->left = NULL;
    root = newnode;
    return root;
}

NODE insert_rear(NODE root,int ele)
{
    NODE temp;
    NODE newnode = getnode(ele);
    temp = root;
    if(root == NULL)
    {
        printf("List is Empty");
        return newnode;
    }
    while(temp->right != NULL)
    {

        temp=temp->right;
    }
    temp->right = newnode;
    newnode->left = temp;
    return root;
}

NODE delete_front(NODE root)
{
    NODE temp;
    if(root == NULL)
    {
        printf("List is Empty");
        return NULL;
    }
    if(root->right == NULL)
    {
        printf("Deleted Element is %d",root->data);
        free(root);
        return root;
    }
    temp = root;
    root = temp->right;
    root->left = NULL;
    printf("Deleted Element is %d",temp->data);
    free(temp);
    return root;
}

NODE delete_rear(NODE root)
{
    NODE temp;
    if(root == NULL)
    {
        printf("List is Empty");
        return NULL;
    }
    if(root->right == NULL)
    {
        printf("Deleted Element is %d",root->data);
        free(root);
        return root;
    }
    NODE prev;
    while(temp->right != NULL)
    {
        prev=temp;
        temp=temp->right;
    }
    prev->right = NULL;
    printf("Deleted Element is %d",temp->data);
    free(temp);
    return root;
}

NODE insert_pos(NODE root,int pos,int ele)
{
    NODE temp,prev;
    int count = 1;
    if(root == NULL || pos == 1)
    {
        root = insert_front(root,ele);
        return root;
    }
    temp = root;
    prev = NULL;
    while(temp->right != NULL)
    {
        if(count == pos)
        break;

        prev = temp;
        temp=temp->right;
        count++;
    }
    NODE newnode = getnode(ele);
    if(count == pos)
    {
        prev->right = newnode;
        newnode->right = temp;
        temp->left = newnode;
        newnode->left = prev;
        return root;
    }
    root = insert_rear(root,ele);
    return root;
}

NODE delete_pos(NODE root, int pos) {
    NODE temp = root;
    int i = 1;

    if (root == NULL) {
        printf("List is Empty");
        return root;
    }

    if (pos == 1) {
        
        return delete_front(root); 
    }

    while (i < pos && temp != NULL) {
        temp = temp->right;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position");
        return root;
    }

    if (temp->left != NULL) {
        temp->left->right = temp->right;
    }

    if (temp->right != NULL) {
        temp->right->left = temp->left;
    }

    if (temp == root) {
        root = temp->right;
    }
    printf("Deleted Element is: %d",temp->data);
    free(temp);
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
        temp=temp->right;
    }
    return -1;
}

void display(NODE root)
{
    NODE temp;
    temp = root;
    if(root == NULL)
    {
        printf("List is Empty");
        return;
    }
    else{
        printf("List is:" );
        while (temp != NULL)
        {
            printf(" %d",temp->data);
            temp=temp->right;
        }
    }
}

int main()
{
    NODE root = NULL;
    int item,chk,pos;
    while(1)
    {
        printf("\n---------------WELCOME TO THE MENU---------------");
        printf("\n1.Insert at Front \n2.Insert at Back \n3.Delete at Front \n4.Delete at Back \n5.Insert at Positon \n6.Delete at Position \n7.Search \n8.Display \n9.Exit\n");
        printf("Enter your choice?\n");
        scanf("%d",&chk);
        switch(chk)
        {
            case 1:
                printf("Enter the Element: ");
                scanf("%d",&item);
                root = insert_front(root,item);
            break;

            case 2:
                printf("Enter the Element: ");
                scanf("%d",&item);
                root = insert_rear(root,item);
            break;

            case 3:
                root = delete_front(root);
            break;

            case 4:
                root = delete_rear(root);
            break;

            case 5:
                printf("Enter the position: ");
                scanf("%d",&pos);
                printf("Enter the Element: ");
                scanf("%d",&item);
                root = insert_pos(root,pos,item);
            break;

            case 6:
                printf("Enter the position: ");
                scanf("%d",&pos);
                root = delete_pos(root,pos);
            break;
            
            case 7:
                printf("Enter the Element: ");
                scanf("%d",&item);
                pos = search(root,item);
                printf("%d Element is at Positon %d",item,pos);
            break;

            case 8:
                display(root);
            break;

            case 9:
                exit(0);
            break;

            default:
                printf("Invalid Choice");
            break;
        }
    }
}