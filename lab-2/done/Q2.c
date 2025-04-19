#include <stdio.h>
#include <time.h>

int linear_Search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void reverse_Array(int arr[], int size)
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

int main()
{
    int sizes[] = {5, 10, 15};
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < 3; i++)
    {
        int size = sizes[i];
        int arr[size];

        printf("Array size: %d\n", size);
        printf("Array elements: ");
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[j]);
        }

        int target;
        printf("Enter the element to be searched: ");
        scanf("%d", &target);

        start = clock();
        int result = linear_Search(arr, size, target);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        if (result != -1)
        {
            printf("Searched element present at location %d\n", result);
        }
        else
        {
            printf("Searched element not found\n");
        }
        printf("Time taken for search: %lf seconds\n", cpu_time_used);

        start = clock();
        reverse_Array(arr, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken for array reversal: %lf seconds\n", cpu_time_used);
    }

    return 0;
}