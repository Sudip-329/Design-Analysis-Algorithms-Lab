//1. Implement Activity selection for a given set of activities for which the 
//start time and finish times are provided.

#include <stdio.h>

void printMaxActivities(int s[], int f[], int n)
{
	int i, j;

	printf("Following activities are selected\n");

	i = 0;
	printf("%d ", i);

	for (j = 1; j < n; j++) {
		if (s[j] >= f[i]) {
			printf("%d ", j); 
			i = j;
		}
	}
}

int main()
{
	//int s[] = { 1,3,2,4,8,7,9,11,9,12 };
	//int f[] = { 3,4,5,7,9,10,11,12,13,14};
    int s[] = {1,3,0,5,5,8};
    int f[] = {2,4,6,7,9,9}; 
	//int s[] = {1,2,0,4,7,6};
    //int f[] = {1,3,2,6,8,4}; 
	int n = sizeof(s) / sizeof(s[0]);

	// Function call
	printMaxActivities(s, f, n);
	return 0;
}
