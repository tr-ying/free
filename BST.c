#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

int calculate_height(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = calculate_height(root->left);
    int rightHeight = calculate_height(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void level_Order(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front < rear) {
        struct Node* temp = queue[++front];
        printf("%d ", temp->data);

        if (temp->left)
            queue[++rear] = temp->left;

        if (temp->right)
            queue[++rear] = temp->right;
    }
}

int isMirror(struct Node* a, struct Node* b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return (a->data == b->data) && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

void printLeafNodes(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}


int check_BST(struct Node* node, int min, int max) {
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return check_BST(node->left, min, node->data - 1) && check_BST(node->right, node->data + 1, max);
}

int isBST(struct Node* root) {
    return check_BST(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    do {
        printf("-------------------------------------------------\n");
        printf("1.Insert Node\n2.Calculate the Height of BST\n3.Level Order Traversal\n4.Mirror Image\n5.Leaf Nodes\n6.Construct Mirror Image\n7.Check whether it's a BST or not\n8.Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data you want to insert = ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                printf("Height of BST = %d\n", calculate_height(root));
                break;

            case 3:
                printf("Level Order Traversal = ");
                level_Order(root);
                printf("\n");
                break;

            case 4:
                if (isMirror(root, root))
                    printf("The given tree has a mirror image.\n");
                else
                    printf("The given tree does not have a mirror image.\n");
                break;

            case 5:
                printf("Leaf nodes = ");
                printLeafNodes(root);
                printf("\n");
                break;

            case 6:
                if (isBST(root))
                    printf("The given tree is a BST.\n");
                else
                    printf("The given tree is not a BST.\n");
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Please Enter Valid Choice!!!!!\n");
        }
    } while (choice != 7);

    return 0;
}

