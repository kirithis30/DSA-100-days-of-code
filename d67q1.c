//Day 67 - Question 1: Topological Sort (DFS)

//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>

int graph[20][20], visited[20], stack[20];
int top = -1, n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v; 
}

int main() {
    int edges, u, v;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}