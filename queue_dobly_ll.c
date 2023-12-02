#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

struct Queue {
    Node* front;
    Node* rear;
};

typedef struct Queue Queue;

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

Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
        newNode->prev = queue->rear;
    }

    queue->rear = newNode;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = queue->front;
    int removedValue = temp->data;

    queue->front = temp->next;
    if (queue->front != NULL) {
        queue->front->prev = NULL;
    } else {
        queue->rear = NULL;
    }

    free(temp);
    return removedValue;
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    Queue* queue = initializeQueue();
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                if (!isEmpty(queue)) {
                    printf("Dequeued element: %d\n", dequeue(queue));
                } else {
                    printf("Queue is empty, cannot dequeue\n");
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                freeQueue(queue);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
