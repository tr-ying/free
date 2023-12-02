#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

void adj_list_creation(struct Node* adj_list[], int v) {
    for (int i = 0; i < v; i++) {
        adj_list[i] = NULL;
    }
}

void adj_list_fill(struct Node* adj_list[], int e) {
    for (int i = 0; i < e; i++) {
        int j, k;
        printf("edges to be added between node (eg:- A B)->\n");
        scanf("%d", &j);
        scanf("%d", &k);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = k;
        newNode->next = adj_list[j];
        adj_list[j] = newNode;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = j;
        newNode->next = adj_list[k];
        adj_list[k] = newNode;
    }
}

struct stack {
    char data[100];
    int top;
};

void push(struct stack *s, char value) {
    if (s->top == 99) {
        printf("stack is full");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

char pop(struct stack *s) {
    char value;
    if (s->top == -1) {
        printf("stack is empty");
        return '\0';
    }
    value = s->data[s->top];
    s->top--;
    return value;
}

int emptystack(struct stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int getIndex(char nodes[100], char node, int v) {
    for (int i = 0; i < v; i++) {
        if (nodes[i] == node) {
            return i;
        }
    }
    return -1;
}

void dfs(struct Node* adj_list[], char nodes[100], int v) {
    struct stack s;
    s.top = -1;
    char v1;
    int vis[100];
    for(int i=0; i<v; i++)
        vis[i]=0;
    printf("enter starting node(value)-> ");
    scanf(" %c",&v1);
    push(&s, v1);

    while (!emptystack(&s)) {
        v1 = pop(&s);
        if (vis[getIndex(nodes, v1, v)] == 0) {
            printf("%c\t", v1);
            vis[getIndex(nodes, v1, v)] = 1;

            struct Node* current = adj_list[getIndex(nodes, v1, v)];
            while (current != NULL) {
                int i = current->vertex;  // Get the correct vertex index
                if (vis[i] != 1) {
                    push(&s, nodes[i]);
                }
                current = current->next;
            }
        }
    }
}

int main() {
    int v, e;
    char nodes[100];
    printf("enter number of vertices-> ");
    scanf("%d", &v);
    printf("enter number of edges-> ");
    scanf("%d", &e);
    for (int i = 0; i < v; i++) {
        printf("add value to the nodes-> \n");
        scanf(" %c", &nodes[i]);
    }

    struct Node* adj_list[100];
    adj_list_creation(adj_list, v);
    adj_list_fill(adj_list, e);

    printf("\n");
    printf("your adjacency list is->\n");
    for (int i = 0; i < v; i++) {
        printf("%c -> ", nodes[i]);
        struct Node* current = adj_list[i];
        while (current != NULL) {
            printf("%c ", nodes[current->vertex]);
            current = current->next;
        }
        printf("\n");
    }

    printf("\nDFS traversal: ");
    dfs(adj_list, nodes, v);

    for (int i = 0; i < v; i++) {
        struct Node* current = adj_list[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}


/*
enter number of vertices-> 5
enter number of edges-> 6
add value to the nodes-> 
A
add value to the nodes-> 
B
add value to the nodes-> 
C
add value to the nodes-> 
D
add value to the nodes-> 
E
edges to be added between node (eg:- A B)->
0 1
edges to be added between node (eg:- A B)->
0 2
edges to be added between node (eg:- A B)->
1 3
edges to be added between node (eg:- A B)->
1 4
edges to be added between node (eg:- A B)->
2 3
edges to be added between node (eg:- A B)->
3 4

*/