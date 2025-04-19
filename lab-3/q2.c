#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator with current time

    int sizes[] = {100, 500, 1000, 1500, 4000, 4500, 5000, 7000, 8000, 10000};

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); ++i) {
        int n = sizes[i];
        int arr[n];

        for (int j = 0; j < n; ++j) {
            arr[j] = rand();
        }

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("n=%d, Time taken: %lf seconds\n", n, time_taken);
    }

    return 0;
}