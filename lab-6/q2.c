//2. Implement Activity selection for a given set of activities for which 
//deadlines and profits are given. Also compute the profit obtained.


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {

	char id; 
	int dead ; 
	int profit; 
} Job;

int compare(const void* a, const void* b)
{
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->profit - temp1->profit);
}


int min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	qsort(arr, n, sizeof(Job), compare);

	int result[n];
	bool slot[n];

	for (int i = 0; i < n; i++)
		slot[i] = false;


	for (int i = 0; i < n; i++) {
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
	int sum = 0;

	for (int i = 0; i < n; i++){
		if (slot[i]){
			printf("%c ", arr[result[i]].id);
			sum = sum +arr[result[i]].profit;
		}
	}
	printf("Total profit : %d",sum);
}

int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };

	/*Job arr[] = { { 'a', 2,20 },
				{ 'b', 2, 15},
				{ 'c', 1, 10 },
				{ 'd', 3, 5 },
				{ 'e', 3, 1}};*/

	/*Job arr[] = { { 'a', 3, 35},
				{ 'b', 4, 30 },
				{ 'c', 4, 25 },
				{ 'd', 2, 20 },
				{ 'e', 3, 15 },
				{ 'f', 1, 12 },
				{ 'g', 2, 5 } };*/
	int n = sizeof(arr) / sizeof(arr[0]);
	printf(
		"Following is maximum profit sequence of jobs \n");

	printJobScheduling(arr, n);
	return 0;
}
