//Day 79 - Question 1: Single Source Shortest Path using Dijkstra’s Algorithm

//Problem Statement
//Find shortest distances from source vertex in a weighted graph with non-negative weights.

//Input Format
//n m
//u v w
//source

//Output Format
//Distances to all vertices.

//Sample Input
//5 6
//1 2 2
//1 3 4
//2 3 1
//2 4 7
//3 5 3
//4 5 1
//1

//Sample Output
//0 2 3 9 6

//Explanation
//Shortest distances computed via priority queue.

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];

void dijkstra(int n, int source) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int n, m, u, v, w, source;

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    scanf("%d", &source);

    dijkstra(n, source);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}