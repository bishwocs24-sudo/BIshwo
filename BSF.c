#include <stdio.h>

int n;
int graph[10][10];
int visited[10];
int queue[10];
int front = -1, rear = -1;

/* Enqueue */
void enqueue(int v) {
    if (rear == -1)
        front = 0;
    queue[++rear] = v;
}

/* Dequeue */
int dequeue() {
    return queue[front++];
}

/* BFS Function */
void bfs(int start) {
    int i, v;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

/* Main Function */
int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
