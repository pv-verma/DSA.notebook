#include <iostream>
using namespace std;

// Inserts arr[n-1] into the sorted arr[0..n-2]
void insertLast(int arr[], int n) {
    if (n <= 1) return;   // base case: single element is already sorted

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void recursiveInsertionSort(int arr[], int n) {
    if (n <= 1) return;              // base case: array of size 0 or 1

    recursiveInsertionSort(arr, n - 1);  // sort first n-1 elements
    insertLast(arr, n);                  // insert nth element into sorted part
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    recursiveInsertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}