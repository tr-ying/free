#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int lbit;
    int rbit;
};

struct node *createnode(struct node *head, int key)
{
    struct node *temp;
    struct node *p;
    p = head->left;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->lbit = 0;
    temp->rbit = 0;

    if (head->left == head)
    {
        temp->left = head->left;
        temp->right = head;
        head->left = temp;
        head->lbit = 1;
        return head;
    }

    while (1)
    {
        if (key < p->data)
        {
            if (p->lbit == 1)
                p = p->left;
            else
                break;
        }
        else if (key > p->data)
        {
            if (p->rbit == 1)
                p = p->right;
            else
                break;
        }
        else
        {
            // Duplicate keys not allowed in threaded binary tree
            printf("Duplicate key %d not allowed!\n", key);
            return head;
        }
    }

    if (key < p->data)
    {
        temp->left = head;
        temp->right = p;
        p->left = temp;
        p->lbit = 1;
    }
    else
    {
        temp->left = p;
        temp->right = p->right;
        p->right = temp;
        p->rbit = 1;
    }

    return head;
}

// Function to perform inorder traversal of the threaded binary tree
void inorder(struct node *head)
{
    struct node *p = head->left;
    while (p != head)
    {
        while (p->lbit == 1)
        {
            p = p->left;
        }
        printf("%d ", p->data);
        while (p->rbit == 0)
        {
            p = p->right;
            if (p == head)
            {
                return;
            }
            printf("%d ", p->data);
        }
        p = p->right;
    }
}

void preorder(struct node *head)
{
    struct node *t = head->left;
    while (t != head)
    {
        while (t->lbit == 1)
        {
            printf("%d ", t->data);
            t = t->left;
        }
        printf("%d ", t->data);
        while (t->rbit == 0)
        {
            t = t->right;
            if (t == head)
            {
                return;
            }
        }
        t = t->right;
    }
}

void postorder(struct node* head)
{
    struct node* p = head->left;
    while (p != head)
    {
        while (p->rbit == 0)
        {
            p = p->right;
        }
        printf("%d ", p->data);
        while (p->lbit == 1)
        {
            printf("%d ", p->data);
            p = p->left;
        }
        p = p->right;
    }
}


int main()
{
    int key;
    int n;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->lbit = head->rbit = 1;
    head->left = head->right = head;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &key);
        head = createnode(head, key);
    }

    int choice;
    printf("Select traversal type:\n");
    printf("1. Inorder Traversal\n");
    printf("2. Preorder Traversal\n");
    printf("3. Postorder Traversal\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Inorder Traversal: ");
            inorder(head);
            printf("\n");
            break;
        case 2:
            printf("Preorder Traversal: ");
            preorder(head);
            printf("\n");
            break;
        case 3:
            printf("Postorder Traversal: ");
            postorder(head);
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

