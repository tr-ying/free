#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data[100];
    int top;
};

void push(struct stack *s, int value) {
    if (s->top == 99) {
        printf("stack is full");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(struct stack *s) {
    int value;
    if (s->top == -1) {
        printf("stack is empty");
        return -1;
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

void matrix_creation(int adj[100][100], int v) {
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
}

void matrix_fill(int adj[100][100], int e) {
    for (int i = 0; i < e; i++) {
        int j, k;
        printf("Enter the nodes for an edge (e.g., 0 1): ");
        scanf("%d %d", &j, &k);
        adj[j][k] = adj[k][j] = 1;
    }
}

void matrix_print(int adj[100][100], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void dfs(int adj[100][100], char nodes[100], int v, int start) {
    struct stack s;
    s.top = -1;
    int visited[100] = {0};
    push(&s, start);

    while (!emptystack(&s)) {
        int current = pop(&s);
        if (!visited[current]) {
            printf("%c\t", nodes[current]);
            visited[current] = 1;

            for (int i = v - 1; i >= 0; i--) {
                if (adj[current][i] == 1 && !visited[i]) {
                    push(&s, i);
                }
            }
        }
    }
}

int main() {
    int adj[100][100], v, e;
    char nodes[100];
    printf("Enter number of vertices-> ");
    scanf("%d", &v);
    printf("Enter number of edges-> ");
    scanf("%d", &e);
    getchar();
    for (int i = 0; i < v; i++) {
        printf("Add value to the nodes-> \n");
        scanf(" %c", &nodes[i]);
    }

    matrix_creation(adj, v);
    matrix_fill(adj, e);
    printf("\n");
    printf("Your matrix is:\n");
    matrix_print(adj, v);

    printf("DFS traversal:\n");
    dfs(adj, nodes, v, 0);

    return 0;
}

/*
Enter number of vertices-> 5
Enter number of edges-> 6
Add value to the nodes-> 
A
Add value to the nodes-> 
B
Add value to the nodes-> 
C
Add value to the nodes-> 
D
Add value to the nodes-> 
E
Enter the nodes for an edge (e.g., 0 1): 0 1
Enter the nodes for an edge (e.g., 0 1): 0 2
Enter the nodes for an edge (e.g., 0 1): 1 3
Enter the nodes for an edge (e.g., 0 1): 1 4
Enter the nodes for an edge (e.g., 0 1): 2 3
Enter the nodes for an edge (e.g., 0 1): 3 4

*/