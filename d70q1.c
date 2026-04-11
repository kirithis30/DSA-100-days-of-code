//Day 70 - Question 1: Bellman-Ford Algorithm

//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

//Input:
//- n vertices
//- m edges (u,v,w)

//Output:
//- Shortest distances OR NEGATIVE CYCLE


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            printf("INF ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

int main() {
    int n = 5;
    int m = 8;
    struct Edge edges[] = {
        {1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 4, 2}, 
        {2, 5, 2}, {4, 2, 1}, {4, 3, 5}, {5, 4, -3}
    };

    bellmanFord(n, m, edges, 1);

    return 0;
}