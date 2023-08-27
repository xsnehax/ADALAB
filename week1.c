#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int a[MAX_VERTICES][MAX_VERTICES], vis[MAX_VERTICES];
int n;

void DFS(int V) {
    vis[V] = 1;
    for (int i = 0; i < n; i++) {
        if (a[V][i] == 1 && vis[i] == 0) {
            DFS(i);
        }
    }
}

void isConnectedDFS() {
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    isConnectedDFS();

    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            printf("The graph is not connected.\n");
            return 0;
        }
    }

    printf("The graph is connected.\n");

    return 0;
}
