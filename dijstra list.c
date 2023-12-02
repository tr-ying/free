#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};
struct AdjList {
    struct AdjListNode* head;
};
struct Graph {
    int V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(struct Graph* graph, int src,int V) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        struct AdjListNode* node = graph->array[u].head;
        while (node) {
            int v = node->dest;
            if (!sptSet[v] && dist[u] != INT_MAX &&
                dist[u] + node->weight < dist[v]) {
                dist[v] = dist[u] + node->weight;
            }
            node = node->next;
        }
    }

    printSolution(dist, V);
}
int main() {
    int V, E, src;
    printf("---------------------------------------------------\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("---------------------------------------------------\n");
    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("---------------------------------------------------\n");
        printf("Enter edge %d (source, destination, weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
    printf("---------------------------------------------------\n");
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, src,V);
    printf("---------------------------------------------------\n");

    return 0;
}


/*
Enter the number of vertices: 5
Enter the number of edges: 6
---------------------------------------------------
Enter edge 1 (source, destination, weight): 0 1 4
---------------------------------------------------
Enter edge 2 (source, destination, weight): 0 2 2
---------------------------------------------------
Enter edge 3 (source, destination, weight): 1 2 5
---------------------------------------------------
Enter edge 4 (source, destination, weight): 1 3 10
---------------------------------------------------
Enter edge 5 (source, destination, weight): 2 3 3
---------------------------------------------------
Enter edge 6 (source, destination, weight): 3 4 1
---------------------------------------------------
Enter the source vertex: 0

*/