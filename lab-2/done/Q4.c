#include <stdio.h>
#include <time.h>

void decimalToBin(int d, char bin[], int binSize)
{
    for (int i = binSize - 1; i >= 0; i--)
    {
        bin[i] = (d % 2) + '0';   //The remainder of the division of d by 2 gives the least significant bit of t
        //he binary representation. Adding '0' to it converts the integer digit into its character equivalent 
        //('0' or '1') and stores it in the corresponding position of the bin array.
        d /= 2; //one bit to the right
    }
    bin[binSize] = '\0'; //end of string.
}

int main()
{
    int arraySizes[] = {5, 10, 15};
    clock_t startTime, endTime;

    for (int k = 0; k < sizeof(arraySizes) / sizeof(arraySizes[0]); k++)
    {
        int size = arraySizes[k];
        int dArray[size];
        char binArray[size][33];

        printf("Enter %d decimal numbers:\n", size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &dArray[i]);
        }

        startTime = clock();
        for (int i = 0; i < size; i++)
        {
            decimalToBin(dArray[i], binArray[i], 8);
        }
        endTime = clock();

        printf("Bin representation of numbers:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d: %s\n", dArray[i], binArray[i]);
        }

        double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        printf("Time taken for array of size %d: %f seconds\n", size, timeTaken);
    }

    return 0;
}