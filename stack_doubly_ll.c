#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

struct Stack {
    Node* top;
};

typedef struct Stack Stack;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Stack* initializeStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);

    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->prev = stack->top;
        stack->top->next = newNode;
        stack->top = newNode;
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    int poppedValue = temp->data;

    stack->top = temp->prev;
    if (stack->top != NULL) {
        stack->top->next = NULL;
    }

    free(temp);
    return poppedValue;
}

void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    Stack* stack = initializeStack();
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                if (!isEmpty(stack)) {
                    printf("Popped element: %d\n", pop(stack));
                } else {
                    printf("Stack is empty, cannot pop\n");
                }
                break;
            case 3:
                displayStack(stack);
                break;
            case 4:
                freeStack(stack);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


