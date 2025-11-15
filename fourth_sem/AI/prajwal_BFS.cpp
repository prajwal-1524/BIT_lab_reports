#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], queue[MAX];
int n, front = 0, rear = 0;

void bfs(int start) {
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n * n; i++)
        scanf("%d", &adj[i / n][i % n]);

    printf("Enter start node: ");
    scanf("%d", &start);

    bfs(start);
    return 0;
}
