#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_VERTICES];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_VERTICES; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void bfsAdjacencyList(struct Graph* graph, int start) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    printf("BFS Traversal: ");
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        struct Node* neighborNode = graph->adjList[vertex];
        while (neighborNode) {
            int neighbor = neighborNode->data;
            if (!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = true;
            }
            neighborNode = neighborNode->next;
        }
    }
    printf("\n");
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");   // 5
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph();

    printf("Enter the number of edges: ");      // 6
    scanf("%d", &numEdges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");              // 0
    scanf("%d", &startVertex);

    printf("Adjacency List:\n");
    for (int i = 0; i < numVertices; ++i) {
        struct Node* current = graph->adjList[i];
        printf("%d: ", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }

    printf("BFS traversal starting from vertex %d:\n", startVertex);
    bfsAdjacencyList(graph, startVertex);

    for (int i = 0; i < numVertices; ++i) {
        struct Node* current = graph->adjList[i];
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}

/*
0 1
0 2
1 3
1 4
2 3
3 4

*/

