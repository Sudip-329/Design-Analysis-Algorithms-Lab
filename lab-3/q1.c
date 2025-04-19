#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    } 
    return -1;
}

void generateRandomArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000;
    }
}

int main()
{
    srand(time(NULL)); // it Seed the random number generator

    int sizes[] = {100, 500, 1000, 1500, 4000, 4500, 5000, 7000, 8000, 10000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++)
    {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));

        generateRandomArray(arr, size);

        int key = arr[rand() % size]; // Choose a random element from the array as the key
        clock_t start = clock();
        int index = binarySearch(arr, size, key);
        clock_t end = clock();

        double timeTaken = ((double)(end - start))/CLOCKS_PER_SEC;

        printf("n=%d, Time taken: %lf seconds\n", size, timeTaken);

        free(arr);
    }

    return 0;
}