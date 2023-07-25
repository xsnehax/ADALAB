#include <stdio.h>
#include <stdbool.h>

int dp[100][100];
bool selected[100][100];
bool selectedObjects[100];

int knapSack(int ind, int sum, int weight[], int profit[], int n) {
    if (sum == 0 || ind < 0)
        return 0;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int take = -1e8;
    bool take_item = false;

    if (sum >= weight[ind]) {
        take = profit[ind] + knapSack(ind - 1, sum - weight[ind], weight, profit, n);
        take_item = true;
    }

    int notTake = knapSack(ind - 1, sum, weight, profit, n);

    if (take >= notTake) {
        selected[ind][sum] = take_item;
        return dp[ind][sum] = take;
    } else {
        selected[ind][sum] = false;
        return dp[ind][sum] = notTake;
    }
}

void printSelectedItems(int n, int size, int weight[], int profit[]) {
    int i = n - 1;
    int j = size;
    printf("Selected items:\n");
    while (i >= 0 && j > 0) {
        if (selected[i][j]) {
            selectedObjects[i] = true;
            j -= weight[i];
        } else {
            selectedObjects[i] = false;
        }
        i--;
    }

    for (int i = 0; i < n; i++) {
        if (selectedObjects[i]) {
            printf("Item %d with weight %d and profit %d\n", i + 1, weight[i], profit[i]);
        }
    }
}

int main() {
    int n, size;
    printf("Enter no.of items and size of the sack\n");
    scanf("%d %d", &n, &size);

    int weight[n], profit[n];
    printf("Enter weight and respective profits\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
            selected[i][j] = false;
        }
    }

    printf("The maximum profit earned is %d\n", knapSack(n - 1, size, weight, profit, n));

    printSelectedItems(n, size, weight, profit);

    return 0;
}
