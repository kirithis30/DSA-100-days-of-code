//Day 63 - Question 1: Depth First Search (DFS)

//Problem: Perform DFS starting from a given source vertex using recursion.

//Input:
//- n
//- adjacency list
//- starting vertex s

//Output:
//- DFS traversal order

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int s;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(s);

    return 0;
}