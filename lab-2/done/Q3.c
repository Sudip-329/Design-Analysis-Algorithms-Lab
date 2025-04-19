#include <stdio.h>
#include <time.h>

    void process_Array(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 15 == 0)
            {
                arr[i] *= 15;
            }
            else if (arr[i] % 5 == 0)
            {
                arr[i] *= 5;
            }
            else if (arr[i] % 3 == 0)
            {
                arr[i] = 3;
            }
            else
            {
                arr[i] = 0;
            }
        }
    }

    int main()
    {
        int array_size;
        printf("Array size: ");
        scanf("%d", &array_size);

        int original_array[array_size];

        for (int i = 0; i < array_size; i++)
        {
            scanf("%d", &original_array[i]);
        }

        clock_t start_time = clock();
        process_Array(original_array, array_size);
        clock_t end_time = clock();

        printf("Original array:\n");
        for (int i = 0; i < array_size; i++)
        {
            printf("%d ", original_array[i]);
        }
        printf("\n");

        printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

       return 0;
    }