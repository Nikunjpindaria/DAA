#include <stdio.h>

#define V 7  

void dfsHelper(int graph[V][V], int visited[V], int key) {
    visited[key] = 1;
    printf("%d ", key + 1); 

    for (int i = 0; i < V; i++) {
        if (graph[key][i] && !visited[i]) {
            dfsHelper(graph, visited, i);
        }
    }
}


void dfs(int graph[V][V]) {
    int visited[V] = {0};
    dfsHelper(graph, visited, 0);  
}

int main() {
    int graph[V][V] = {
      // A  B  C  D  E  F  G
        {0, 1, 0, 1, 0, 0, 0},  // A
        {1, 0, 1, 1, 1, 0, 0},  // B
        {0, 1, 0, 0, 1, 0, 0},  // C
        {1, 1, 0, 0, 1, 0, 0},  // D
        {0, 1, 1, 1, 0, 1, 1},  // E
        {0, 0, 0, 1, 1, 0, 1},  // F
        {0, 0, 0, 0, 1, 1, 0}   // G
    };

    printf("DFS Traversal: ");
    dfs(graph);

    return 0;
}
