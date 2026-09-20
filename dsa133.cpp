// Find the Sum of Array Elements Using Pointer Arithmetic

#include <iostream>
using namespace std;

int sumArray(int* arr, int n) {
    int sum = 0;
    int* ptr = arr;   // ptr points to the first element

    for (int i = 0; i < n; i++) {
        sum += *ptr;   // dereference to get current value
        ptr++;         // move pointer to next element
    }

    return sum;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int total = sumArray(arr, n);

    cout << "Sum of array elements: " << total << endl;

    return 0;
}