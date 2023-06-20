#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 10

int a[MAX_VERTICES][MAX_VERTICES], vis[MAX_VERTICES];
int n;

void DFS(int V) {
    vis[V] = 1;
    printf("%d ", V);
    for (int i = 1; i <= n; i++) {
        if (a[V][i] == 1 && vis[i] == 0) {
            DFS(i);
        }
    }
}

bool isConnectedGraph() {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    // Find the first vertex that is reachable from the previous vertex
    int startVertex = 1;
    while (vis[startVertex] == 0)
        startVertex++;

    DFS(startVertex);

    // Check if all vertices are visited
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)
            return false;
    }

    return true;
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if (isConnectedGraph()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
