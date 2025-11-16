#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

int n;  // number of nodes
int adj[MAX][MAX];  // adjacency matrix
int h[MAX];         // heuristic values
int visited[MAX];   // visited flag
int goal;

int findLowestF(int open[], int g[]) {
    int minF = INF, minNode = -1;
    for (int i = 0; i < n; i++) {
        if (open[i] && !visited[i]) {
            int f = g[i] + h[i];
            if (f < minF) {
                minF = f;
                minNode = i;
            }
        }
    }
    return minNode;
}

void aStar(int start) {
    int g[MAX] = {0}; // g[n] = cost from start to n
    int open[MAX] = {0}; // open set
    open[start] = 1;

    printf("Path: ");
    while (1) {
        int current = findLowestF(open, g);
        if (current == -1) {
            printf("\nNo path found to goal.\n");
            return;
        }

        printf("%d ", current);
        visited[current] = 1;

        if (current == goal) {
            printf("\nGoal node %d reached!\n", goal);
            return;
        }

        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                if (!open[i] || g[current] + adj[current][i] < g[i]) {
                    g[i] = g[current] + adj[current][i];
                    open[i] = 1;
                }
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge, else cost):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter heuristic values (h) for each node:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    aStar(start);

    return 0;
}

