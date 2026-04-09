//Day 68 - Question 1: Topological Sort (Kahnâ€™s BFS Algorithm)

//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>

int main() {
    int n, edges, u, v;
    int adj[20][20] = {0}, indegree[20] = {0}, queue[20];
    int front = 0, rear = 0;

    scanf("%d", &n);
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while(front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for(int next = 0; next < n; next++) {
            if(adj[current][next] == 1) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    queue[rear++] = next;
                }
            }
        }
    }

    return 0;
}