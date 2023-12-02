#include <stdio.h>
#include <stdlib.h>

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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}


struct Node* searchMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* delNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = delNode(root->left, data);
    } else if (data > root->data) {
        root->right = delNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* minRight = searchMin(root->right);
        root->data = minRight->data;
        root->right = delNode(root->right, minRight->data);
    }
    return root;
}

void preTrav(struct Node *node){
    struct Node *stack[10];
    int top=-1;
    while(node!=NULL ){
        printf("%d ",node->data);
        stack[++top]=node;
        node=node->left;
    }
    while(top!=-1){
        node=stack[top--];
        node=node->right;
        while(node!=NULL){
        printf("%d ",node->data);
        stack[++top]=node;
        node=node->left;
    }
    }
}
void inTrav(struct Node *node){
    struct Node *stack[10];
    int top=-1;
    while(node!=NULL){
        stack[++top]=node;
        node=node->left;
    }
    while(top!=-1){
        node=stack[top--];
        printf("%d ",node->data);
        node=node->right;
        while(node!=NULL){
        stack[++top]=node;
        node=node->left;
    }
    }
}
void postTrav(struct Node* T) {
    if (T == NULL)
        return;

    struct Node* stack[10];
    int top = -1;
    struct Node* prev = NULL;

    do {
        while (T != NULL) {
            stack[++top] = T;
            T = T->left;
        }

        while (T == NULL && top != -1) {
            T = stack[top];
            if (T->right == NULL || T->right == prev) {
                printf("%d ", T->data);
                prev = T;
                top--;
                T = NULL;
            } else {
                T = T->right;
                break;
            }
        }
    } while (top != -1);
}



int main() {
    struct Node* root = NULL;

    int choice, data;

    do {
        printf("-----------------------------------------------\n");
        printf("Press '1' for Inserting element\n");
        printf("Press '2' for Searching element\n");
        printf("Press '3' for Inorder Traversal\n");
        printf("Press '4' for Preorder Traversal\n");
        printf("Press '5' for Postorder Traversal\n");
        printf("Press '6' for Deletion of Node\n");
        printf("Press '7' for Exit\n");
        printf("-----------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("%d found in the binary search tree.\n", data);
                } else {
                    printf("%d not found in the binary search tree.\n", data);
                }
                break;
            case 3:
                printf("Inorder traversal: ");
                inTrav(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preTrav(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postTrav(root);
                printf("\n");
                break;
            case 6:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = delNode(root, data);
                break;
            case 7:
                printf("Exiting...\n");
                break;


            default:
                printf("Please Enter Valid Number\n");
        }
    } while (choice != 7);

    return 0;
}

