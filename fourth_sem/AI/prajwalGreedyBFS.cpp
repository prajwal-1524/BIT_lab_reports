#include <stdio.h>
#define MAX 10
#define INF 9999

int adj[MAX][MAX], h[MAX], visited[MAX], n, goal;

int findBest(int open[]) {
    int min = INF, node = -1;
    for (int i = 0; i < n; i++)
        if (open[i] && !visited[i] && h[i] < min)
            min = h[i], node = i;
    return node;
}

void greedyBFS(int start) {
    int open[MAX] = {0};
    open[start] = 1;

    printf("Greedy BFS Path: ");
    while (1) {
        int current = findBest(open);
        if (current == -1) {
            printf("\nNo path to goal.\n");
            return;
        }

        printf("%d ", current);
        if (current == goal) {
            printf("\nGoal %d reached!\n", goal);
            return;
        }

        visited[current] = 1;

        for (int i = 0; i < n; i++)
            if (adj[current][i] && !visited[i])
                open[i] = 1;
    }
}

int main() {
    int start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n * n; i++)
        scanf("%d", &adj[i / n][i % n]);

    printf("Enter heuristic values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    printf("Enter start and goal node: ");
    scanf("%d %d", &start, &goal);

    greedyBFS(start);
    return 0;
}
