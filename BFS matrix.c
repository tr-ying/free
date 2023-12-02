#include <stdio.h>
#include <stdlib.h>

void matrix_creation(int adj[100][100], int v);
void matrix_fill(int adj[100][100], int e);
void matrix_print(int adj[100][100], int v);
void bfs(int adj[100][100], char nodes[100], int v);

struct queue
{
    char data[100];
    int front, rear;
};

void enqueue(struct queue *q, char value)
{
    if (q->rear == 99)
    {
        printf("queue is full");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

char dequeue(struct queue *q)
{
    char value;
    if (q->front == q->rear)
    {
        printf("queue is empty");
        q->front = q->rear = -1;
        return 0;
    }
    q->front++;
    value = q->data[q->front];
    return value;
}

int emptyqueue(struct queue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void matrix_creation(int adj[100][100], int v)
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
        {
            adj[i][j] = 0;
        }
}

void matrix_fill(int adj[100][100], int e)
{
    int addedEdges[100][100] = {0};

    for (int i = 0; i < e; i++)
    {
        int j, k;
        printf("Enter the node for an edge  ->\n");
        scanf("%d", &j);
        scanf("%d", &k);

        if (!addedEdges[j][k] && !addedEdges[k][j])
        {
            adj[j][k] = adj[k][j] = 1;
            addedEdges[j][k] = addedEdges[k][j] = 1;
        }
    }
}

void matrix_print(int adj[100][100], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int getIndex(char nodes[100], char node, int v)
{
    for (int i = 0; i < v; i++)
    {
        if (nodes[i] == node)
        {
            return i;
        }
    }
    return -1;
}

void bfs(int adj[100][100], char nodes[100], int v)
{
    struct queue q;
    q.front = q.rear = -1;
    int vis[10], rear = -1, in;
    char queue[100], v1;
    for (int i = 0; i < v; i++)
        vis[i] = 0;
    printf("enter starting node(value)-> ");
    fflush(stdin);
    scanf("%c", &v1);
    vis[getIndex(nodes, v1, v)] = 1;
    enqueue(&q, v1);

    while (!emptyqueue(&q))
    {
        v1 = dequeue(&q);
        printf("%c\t", v1);
        for (int i = 0; i < v; i++)
        {
            if ((adj[getIndex(nodes, v1, v)][i] == 1) && (vis[i] != 1))
            {
                enqueue(&q, nodes[i]);
                vis[i] = 1;
            }
        }
    }
}

int main()
{
    int adj[100][100], v, e;
    char nodes[100];
    printf("enter number of vertices-> ");
    scanf("%d", &v);
    printf("enter number of edges-> ");
    scanf("%d", &e);
    for (int i = 0; i < v; i++)
    {
        printf("add value to the nodes-> \n");
        fflush(stdin);
        scanf(" %c", &nodes[i]);
    }

    matrix_creation(adj, v);
    matrix_fill(adj, e);
    printf("\n");
    printf("your matrix is->\n");
    matrix_print(adj, v);
    bfs(adj, nodes, v);
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
Enter the node for an edge ->
0 1
Enter the node for an edge ->
0 2
Enter the node for an edge ->
1 3
Enter the node for an edge ->
1 4
Enter the node for an edge ->
2 3
Enter the node for an edge ->
3 4
*/