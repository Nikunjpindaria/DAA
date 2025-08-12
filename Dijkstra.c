#include <stdio.h>
#include <limits.h>

#define V 5

int findminkey(int visited[V], int distance[V]) {
    int min = INT_MAX;
    int key = -1;
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && distance[i] < min) {
            min = distance[i];
            key = i;
        }
    }
    return key;
}

void dijkstra(int graph[V][V]) {
    int distance[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[0] = 0; 
    for (int i = 0; i < V - 1; i++) {
        int u = findminkey(visited, distance);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, distance[i]);
    }
}

int main() {
    int graph[V][V] = {
    //   0  1  2  3  4
        {0, 9, 75, 0, 0},  // 0
        {0, 0, 95, 0, 42}, // 1
        {0, 0, 0, 51, 0},  // 2
        {0, 19, 0, 0, 0},  // 3
        {0, 0, 0, 31, 0}   // 4
    };

    dijkstra(graph);

    return 0;
}
