#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++)
        if (adj[node][i] && !visited[i])
            dfs(i);
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

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
