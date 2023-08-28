#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int ch;
    int n;
    int A[100];
    clock_t start_time, end_time;

    printf("\n1. For manual entry of N value and array elements\n2. For Random Values of N\n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("Enter array elements\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &A[i]);
                }
                printf("Array Elements: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", A[i]);
                }
                start_time = clock();
                mergeSort(A, 0, n - 1);
                end_time = clock();
                double taken_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                printf("\nSorted Array: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", A[i]);
                }
                printf("\nTime taken: %f seconds\n", taken_time);
                break;

            case 2:
                srand(time(NULL));
                int sizes[] = {10, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};
                int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

                for (int i = 0; i < num_sizes; i++) {
                    int N = sizes[i];
                    int arr[N];

                    for (int j = 0; j < N; j++) {
                        arr[j] = rand() % 1000;
                    }

                    clock_t start = clock();
                    mergeSort(arr, 0, N - 1);
                    clock_t end = clock();
                    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                    printf("Time taken to sort array of size %d: %lf seconds\n", N, time_taken);
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice");
                break;
        }
    }

    return 0;
}
