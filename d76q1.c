//Day 76 - Question 1: Count Connected Components (Undirected Graph)

//Problem Statement
//Using DFS or BFS, count number of connected components.

//Input Format
//n m
//edges

//Output Format
//Number of connected components.

//Sample Input
//6 3
//1 2
//2 3
//5 6

//Sample Output
//3

//Explanation
//Components: {1,2,3}, {4}, {5,6}

#include <stdio.h>
#include <stdlib.h>

int adj[101][101];
int visited[101];

void dfs(int u, int n) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v, n);
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, n);
        }
    }

    printf("%d\n", components);

    return 0;
}