#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
    int balanceFactor;
};

struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->value = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->balanceFactor = 1;
    return newNode;
}

int getNodeHeight(struct TreeNode *node) {
    if (node == NULL) return 0;
    return node->balanceFactor;
}

void updateNodeHeight(struct TreeNode *node) {
    int leftHeight = getNodeHeight(node->leftChild);
    int rightHeight = getNodeHeight(node->rightChild);
    node->balanceFactor = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

struct TreeNode *rotateRight(struct TreeNode *y) {
    struct TreeNode *x = y->leftChild;
    struct TreeNode *T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    updateNodeHeight(y);
    updateNodeHeight(x);

    return x;
}

struct TreeNode *rotateLeft(struct TreeNode *x) {
    struct TreeNode *y = x->rightChild;
    struct TreeNode *T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    updateNodeHeight(x);
    updateNodeHeight(y);

    return y;
}

int getBalanceFactor(struct TreeNode *node) {
    if (node == NULL) return 0;
    return getNodeHeight(node->leftChild) - getNodeHeight(node->rightChild);
}

struct TreeNode *insertNode(struct TreeNode *node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->value)
        node->leftChild = insertNode(node->leftChild, value);
    else if (value > node->value)
        node->rightChild = insertNode(node->rightChild, value);
    else
        return node;

    updateNodeHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (value < node->leftChild->value) {
            return rotateRight(node);
        } else if (value > node->leftChild->value) {
            node->leftChild = rotateLeft(node->leftChild);
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        if (value > node->rightChild->value) {
            return rotateLeft(node);
        } else if (value < node->rightChild->value) {
            node->rightChild = rotateRight(node->rightChild);
            return rotateLeft(node);
        }
    }
    return node;
}

void displayTree(struct TreeNode *root, int level) {
    if (root != NULL) {
        displayTree(root->rightChild, level + 1);
        printf("\n");
        if (root == root->leftChild)
            printf("Root -> ");
        for (int i = 0; i < level && root != root->leftChild; i++)
            printf("        ");
        printf("%d", root->value);
        displayTree(root->leftChild, level + 1);
    }
}

int main() {
    struct TreeNode *root = NULL;
    int choice, data;

    while (1) {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("AVL Tree:");
                displayTree(root, 0);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


