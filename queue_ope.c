#include<stdio.h>
#include<stdlib.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

void enqueueFront(int x) {
    if ((front == 0 && rear == N - 1) || front == rear + 1) {
        printf("Queue is Full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = x;
    } else if (front == 0) {
        front = N - 1;
        queue[front] = x;
    } else {
        front--;
        queue[front] = x;
    }
}

void enqueueRear(int x) {
    if ((front == 0 && rear == N - 1) || front == rear + 1) {
        printf("Queue is Full\n");
    } else if (rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = x;
    } else if (rear == N - 1) {
        rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeueFront() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        front = rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
}

void dequeueRear() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = N - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d ", queue[rear]);
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}
