#include <stdio.h>
#include <time.h>

void reverseArray(int arr[], int size) 
{
    int start = 0;
    int end = size - 1;
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printElapsedTime(clock_t start, clock_t end) {
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", elapsedTime);
}

int main() {
    int array_sizes[] = {7, 3, 12};
    int i, j;

    for (i = 0; i < 3; i++) {
        int size = array_sizes[i];
        int arr[size];

        for (j = 0; j < size; j++) {
            scanf("%d",&arr[j]);
        }

        clock_t start_time = clock();
        reverseArray(arr, size);
        clock_t end_time = clock();

        printf("Array size: %d, ", size);
        printElapsedTime(start_time, end_time);
    }

    return 0;
}
