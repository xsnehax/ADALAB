#include <stdio.h>

#define MAX_NODES 100
#define INF 999

void Dijkstras(int src, int n, int cost[MAX_NODES][MAX_NODES], int dest[MAX_NODES], int vis[MAX_NODES])
{
    int i, count, min, u;

    for (i = 1; i <= n; i++)
    {
        dest[i] = cost[src][i];
        vis[i] = 0;
    }

    vis[src] = 1;
    count = 1;

    while (count < n)
    {
        min = INF;
        for (i = 1; i <= n; i++)
        {
            if (dest[i] < min && vis[i] == 0)
            {
                min = dest[i];
                u = i;
            }
        }

        vis[u] = 1;
        for (i = 1; i <= n; i++)
        {
            if (dest[u] + cost[u][i] < dest[i] && vis[i] == 0)
            {
                dest[i] = dest[u] + cost[u][i];
            }
        }

        count++;
    }
}

int main()
{
    int n, src, i, j;
    int cost[MAX_NODES][MAX_NODES];
    int dest[MAX_NODES];
    int vis[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &src);

    Dijkstras(src, n, cost, dest, vis);

    printf("Shortest distances from node %d to all other nodes:\n", src);
    for (i = 1; i <= n; i++)
    {
        printf("Node %d: %d\n", i, dest[i]);
    }

    return 0;
}
