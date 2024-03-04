#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node *NODE;

NODE getnode(int ele)
{
    NODE p;
    p = (NODE)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("Memory Not Allocated");
        exit(1);
    }
    p->data = ele;
    p->right = NULL;
    p->left = NULL;
    return p;
}

NODE insert(NODE root, int ele)
{
    NODE newnode, prev, cur;
    newnode = getnode(ele);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (cur->data > ele)
        {
            cur = cur->left;
        }
        else if (cur->data < ele)
        {
            cur = cur->right;
        }
        else
        {
            return root;
        }
    }
    if (prev->data > ele)
        prev->left = newnode;
    else
        prev->right = newnode;
    return root;
}

void search(NODE root, int ele)
{
    NODE cur = root;
    while (cur != NULL)
    {
        if (cur->data == ele)
            break;
        else if (cur->data > ele)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == NULL)
    {
        printf("Element not Found");
    }
    else
    {
        printf("Element is present in the Tree");
    }
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

NODE delete(NODE root, int ele)
{
    NODE cur, prev;
    cur = root;
    prev = NULL;
    while (cur != NULL && cur->data != ele)
    {
        prev = cur;
        if (cur->data > ele)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == NULL)
    {
        printf("Element is Not Present in the Tree");
        return root;
    }
    if (cur->left == NULL || cur->right == NULL)
    {
        NODE new;
        if (cur->left == NULL)
            new = cur->right;
        else
            new = cur->left;
        if (prev == NULL)
        {
            printf("Deleted Element is %d", cur->data);
            free(cur);
            return new;
        }
        if (cur == prev->left)
            prev->left = new;
        else
            prev->right = new;
        printf("Deleted Element is %d", cur->data);
        free(cur);
    }
    else
    {
        NODE p, temp;
        p = NULL;
        temp = cur->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        cur->data = temp->data;
        if (p == NULL)
            cur->right = temp->right;
        else
            p->left = temp->right;
        printf("Deleted Element is %d", temp->data);
        free(temp);
        return root;
    }
}

NODE max(NODE root)
{
    if (root == NULL)
        return root;
    NODE temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

NODE min(NODE root)
{
    if (root == NULL)
        return root;
    NODE temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

int count = 0;
void count_leaf(NODE root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        count++;
    count_leaf(root->right);
}

int main()
{
    NODE root = NULL;
    int chk, item;
    while (1)
    {
        printf("\n---------------WELCOME TO THE MENU---------------");
        printf("\n1.Insert \n2.Delete \n3.Inorder Traversal \n4.Preorder Traversal \n5.Postorder Traversal \n6.Max Eelement \n7.Min Element \n8.Search \n9.Leaf Count \n10.Exit");
        printf("\nEnter your choice?");
        scanf("%d", &chk);
        switch (chk)
        {
        case 1:
            printf("Enter the Element: ");
            scanf("%d", &item);
            root = insert(root, item);
            break;

        case 2:
            printf("Enter the Element: ");
            scanf("%d", &item);
            root = delete (root, item);
            break;

        case 3:
            inorder(root);
            break;

        case 4:
            preorder(root);
            break;

        case 5:
            postorder(root);
            break;

        case 6:
            root = max(root);
            printf("Greatest Element in the Tree: %d", root->data);
            break;

        case 7:
            root = min(root);
            printf("Smallest Element in the Tree: %d", root->data);
            break;

        case 8:
            printf("Enter the Element: ");
            scanf("%d", &item);
            search(root, item);
            break;

        case 9:
            count_leaf(root);
            printf("Number of Leafs: %d", count);
            break;

        case 10:
            exit(1);
            break;

        default:
            printf("Invalid Choice");
            break;
        }
    }
}