#include <stdio.h>
#include <limits.h>

#define V 100

int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n);
}

int main() {
    int n, src;
    printf("---------------------------------------------------\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[V][V];
    printf("---------------------------------------------------\n");
    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n---------------------------------------------------\n");
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("---------------------------------------------------\n");
    dijkstra(graph, src, n);
    printf("---------------------------------------------------\n");

    return 0;
}

/* input v-5
    0  3  0  7  0
3  0  8  0  2
0  8  0  9  0
7  0  9  0  6
0  2  0  6  0
*/
