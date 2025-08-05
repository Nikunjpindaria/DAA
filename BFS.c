#include <stdio.h>

#define V 7

void bfs(int graph[V][V]) {
    int visited[V] = {0};
    int queue[100], front = 0, rear = 0;

    visited[0] = 1;
    queue[rear++] = 0;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current + 1);

        for (int i = 0; i < V; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int graph[V][V] = {
     //  A  B  C  D  E  F  G
        {0, 1, 0, 1, 0, 0, 0},  // A
        {1, 0, 1, 1, 1, 0, 0},  // B
        {0, 1, 0, 0, 1, 0, 0},  // C
        {1, 1, 0, 0, 1, 0, 0},  // D
        {0, 1, 1, 1, 0, 1, 1},  // E
        {0, 0, 0, 1, 1, 0, 1},  // F
        {0, 0, 0, 0, 1, 1, 0}   // G
    };

    printf("BFS Traversal: ");
    bfs(graph);

    return 0;
}
