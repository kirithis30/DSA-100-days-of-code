//Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)

//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

//Output:
//- YES or NO

#include <stdio.h>
#include <stdbool.h>

int graph[100][100], visited[100], n;

bool dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node)) return true;
            } 
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int edges, u, v;
    if (scanf("%d %d", &n, &edges) != 2) return 0;

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    bool result = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                result = true;
                break;
            }
        }
    }

    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}