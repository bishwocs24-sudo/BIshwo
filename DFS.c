#include <stdio.h>

int n;
int graph[10][10];
int visited[10];

/* DFS Function */
void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    /* Start DFS from vertex 0 */
    dfs(0);

    /* Check if all vertices are visited */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is CONNECTED\n");
    return 0;
}
