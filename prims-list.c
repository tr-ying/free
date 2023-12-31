#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 9999
#define V 5

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Graph {
    struct Node* head[V];
};

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < V; ++i) {
        graph->head[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->head[src];
    graph->head[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->weight = weight;
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

void primMST(struct Graph* graph) {
    int parent[V];
    int key[V];
    bool inMST[V];

    for (int i = 0; i < V; ++i) {
        key[i] = INF;
        inMST[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u, minKey = INF;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        struct Node* curr = graph->head[u];
        while (curr != NULL) {
            int v = curr->vertex;
            int weight = curr->weight;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            curr = curr->next;
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; ++i) {
        printf("%d - %d \t%d\n", parent[i], i, key[i]);
    }
}

int main() {
    struct Graph* graph = createGraph();
    int edges;

    printf("Enter the number of edges: ");  // 7 
    scanf("%d", &edges);

    printf("Enter the edges and weights (src dest weight):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);

    return 0;
}


/*
0 1 2
0 3 3
1 2 8
1 3 5
1 4 4
2 4 9
3 4 7
*/