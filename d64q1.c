//Day 64 - Question 1: Breadth First Search (BFS)

//Problem: Perform BFS from a given source using queue.

//Input:
//- n
//- adjacency list
//- source s

//Output:
//- BFS traversal order

#include <stdio.h>

void bfs(int n, int adj[n][n], int start) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, s;
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}