//Day 66 - Question 1: Cycle Detection in Directed Graph

//Problem: Detect cycle in directed graph using DFS and recursion stack.

//Output:
//- YES if cycle exists

#include <stdio.h>

int graph[20][20], visited[20], stack[20], n;

int findCycle(int node) {
    visited[node] = 1;
    stack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (stack[i]) return 1; 
            if (!visited[i] && findCycle(i)) return 1;
        }
    }

    stack[node] = 0; 
    return 0;
}

int main() {
    int edges, u, v;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (findCycle(i)) {
                result = 1;
                break;
            }
        }
    }

    if (result) printf("YES\n");
    else printf("NO\n");

    return 0;
}