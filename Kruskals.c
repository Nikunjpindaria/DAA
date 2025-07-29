#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define V 4  // Number of vertices
#define E 5  // Number of edges

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[E] = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
};

// Compare function for qsort
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// Disjoint Set (Union-Find)
int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

int main() {
    // Initialize parent array
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compare);

    int totalWeight = 0;

    printf("Edges in MST:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            unionSet(u, v);
            totalWeight += w;
            printf("%d - %d : %d\n", u, v, w);
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
    return 0;
}
 