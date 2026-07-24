#include <iostream>
using namespace std;

// Find Minimum in Rotated Sorted Array

int findMin(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right = mid;
    }
    return arr[left];
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = 5;
    cout << "Minimum: " << findMin(arr, n) << endl;
    return 0;
}