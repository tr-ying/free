#include <stdio.h>
#include <stdlib.h>
#define INF 10000
struct Edge
{
    int src, dest, weight;
};
struct Node
{
    int dest, weight;
    struct Node *next;
};
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
int findParent(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}
void kruskalMSTMatrix(int graph[][100], int V, int E)
{
    struct Edge edges[V * V];
    int edgeCount = 0;
    for (int i = 0; i < V; ++i)
    {
        for (int j = i + 1; j < V; ++j)
        {
            if (graph[i][j] != INF)
            {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
    qsort(edges, edgeCount, sizeof(struct Edge), compare);
    int parent[V];
    for (int i = 0; i < V; ++i)
        parent[i] = -1;
    struct Edge result[V - 1];
    int resultIndex = 0;
    for (int i = 0; i < edgeCount && resultIndex < V - 1; ++i)
    {
        struct Edge nextEdge = edges[i];
        int srcParent = findParent(parent, nextEdge.src);
        int destParent = findParent(parent, nextEdge.dest);
        if (srcParent != destParent)
        {
            result[resultIndex++] = nextEdge;
            parent[destParent] = srcParent;
        }
    }
    printf("Minimum Spanning Tree using Adjacency Matrix:\n");
    for (int i = 0; i < resultIndex; ++i)
        printf("%d - %d, Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
}
void kruskalMSTList(struct Node *adjacencyList[], int V)
{
    struct Edge edges[V * V];
    int edgeCount = 0;
    for (int i = 0; i < V; ++i)
    {
        struct Node *currentNode = adjacencyList[i];
        while (currentNode != NULL)
        {
            edges[edgeCount].src = i;
            edges[edgeCount].dest = currentNode->dest;
            edges[edgeCount].weight = currentNode->weight;
            edgeCount++;
            currentNode = currentNode->next;
        }
    }
    qsort(edges, edgeCount, sizeof(struct Edge), compare);
    int parent[V];
    for (int i = 0; i < V; ++i)
        parent[i] = -1;
    struct Edge result[V - 1];
    int resultIndex = 0;
    for (int i = 0; i < edgeCount && resultIndex < V - 1; ++i)
    {
        struct Edge nextEdge = edges[i];
        int srcParent = findParent(parent, nextEdge.src);
        int destParent = findParent(parent, nextEdge.dest);
        if (srcParent != destParent)
        {
            result[resultIndex++] = nextEdge;
            parent[destParent] = srcParent;
        }
    }
    printf("Minimum Spanning Tree using Adjacency List:\n");
    for (int i = 0; i < resultIndex; ++i)
        printf("%d - %d, Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
}
int main()
{
    int V, E, choice;
    printf("Enter the number of vertices and edges: ");     // 4 5
    scanf("%d %d", &V, &E);
    int graphMatrix[100][100];
    struct Node *adjacencyList[V];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            graphMatrix[i][j] = INF;
        }
        adjacencyList[i] = NULL;
    }
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; ++i)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graphMatrix[src][dest] = weight;
        graphMatrix[dest][src] = weight;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = adjacencyList[src];
        adjacencyList[src] = newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = src;
        newNode->weight = weight;
        newNode->next = adjacencyList[dest];
        adjacencyList[dest] = newNode;
    }
    do
    {
        printf("\n1. Kruskal using adj matrix");
        printf("\n2.Kruskal using adj list");
        printf("\n3. exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("1. Minimum Spanning Tree using Adjacency Matrix\n");
            kruskalMSTMatrix(graphMatrix, V, E);
            break;
        case 2:
            printf("2. Minimum Spanning Tree using Adjacency List\n");
            kruskalMSTList(adjacencyList, V);
            break;
        case 3:
            printf("exit");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}

/*
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/