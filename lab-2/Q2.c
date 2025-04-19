#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if target element is not found
}

// Function to reverse an array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int sizes[] = {1000, 5000, 10000}; // Array sizes to test
    int target = rand() % 1000; // Element to search for

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); ++i) {
        int size = sizes[i];
        int arr[size];

        // Fill the array with random values
        for (int j = 0; j < size; ++j) {
            arr[j] = rand() % 1000;
        }

        // Measure time taken for linear search
        clock_t start_time = clock();
        int result = linearSearch(arr, size, target);
        clock_t end_time = clock();

        double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Linear search for target %d in array of size %d: ", target, size);
        if (result != -1) {
            printf("Found at index %d\n", result);
        } else {
            printf("Not found\n");
        }
        printf("Time taken: %f seconds\n", search_time);

        // Measure time taken for array reversal
        start_time = clock();
        reverseArray(arr, size);
        end_time = clock();

        double reverse_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("Array of size %d reversed\n", size);
        printf("Time taken to reverse: %f seconds\n", reverse_time);

        printf("\n");
    }

    return 0;
}
