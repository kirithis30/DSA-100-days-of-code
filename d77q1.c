//Day 77 - Question 1: Check if Graph is Connected

//Problem Statement
//Using BFS or DFS, check if the entire graph is connected.

//Input Format
//n m
//edges

//Output Format
//CONNECTED
//NOT CONNECTED

//Sample Input
//4 2
//1 2
//3 4

//Sample Output
//NOT CONNECTED

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

    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    dfs(1, n);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}