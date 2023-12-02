#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

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

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

void displayList(Node* head) {
    printf("Doubly linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int value, position, choice;

    while (1) {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Display the list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
