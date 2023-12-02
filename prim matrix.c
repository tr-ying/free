#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6

intgraph[V][V];

voidinitializeGraph()
{
    for (inti = 0; i < V; i++)
    {
        for (intj = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
}

voidaddEdge(int source, int destination, int weight)
{
    graph[source][destination] = weight;
    graph[destination][source] = weight;
}

intgetMinimumVertex(bool mst[], int key[])
{
    intminKey = INT_MAX;
    intvertex = -1;
    for (inti = 0; i < V; i++)
    {
        if (!mst[i] && minKey > key[i])
        {
            minKey = key[i];
            vertex = i;
        }
    }
    returnvertex;
}

voidprimMST()
{
    boolmst[V];
    intkey[V];

    for (inti = 0; i < V; i++)
    {
        mst[i] = false;
        key[i] = INT_MAX;
    }

    key[0] = 0;

    for (inti = 0; i < V - 1; i++)
    {
        intvertex = getMinimumVertex(mst, key);
        mst[vertex] = true;

        for (intj = 0; j < V; j++)
        {
            if (graph[vertex][j] && !mst[j] && graph[vertex][j] < key[j])
            {
                key[j] = graph[vertex][j];
            }
        }
    }

    inttotal_min_weight = 0;
    printf("Minimum Spanning Tree:\n");
    for (inti = 1; i < V; i++)
    {
        printf("Edge: %d - %d key: %d\n", i, i, key[i]);
        total_min_weight += key[i];
    }
    printf("Total minimum key: %d\n", total_min_weight);
}

intmain()
{
    initializeGraph();

    intedges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (inti = 0; i < edges; i++)
    {
        intsource, destination, weight;
        printf("Enter edge %d source, destination, and weight: ", i + 1);
        scanf("%d%d%d", &source, &destination, &weight);
        addEdge(source, destination, weight);
    }

    primMST();
    return0;
}


/*
8
0 1 4
0 2 5
1 2 3
1 3 2
1 4 6
2 3 1
2 4 7
3 4 8
*/
