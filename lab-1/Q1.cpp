/*Q1. Write a program to find out the second smallest and second largest element stored in an array of n elements.
      ( Take inputs on runtime)*/

/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"How many numbers : ";                     // with sorting
    int n;
    cin>>n;
    int arr[50];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    cout<<"Second largest element"<<(arr[n-2])<<endl;   // Answers...
    cout<<"Second smallest element"<<(arr[1])<<endl;
}*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements :";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int smallest = INT_MAX, second_smallest = INT_MAX;  //maximum variable for int typr data
    int largest = INT_MIN, second_largest = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    cout << "The second smallest element is: " << second_smallest << endl;
    cout << "The second largest element is: " << second_largest << endl;
    return 0;
}
