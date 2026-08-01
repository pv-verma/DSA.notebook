#include <iostream>
using namespace std;

// Function to count inversions in an array using merge sort
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // pointer for left subarray
    int j = mid + 1;   // pointer for right subarray
    int k = left;       // pointer for temp array
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j] means arr[i..mid] are all > arr[j]
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int temp[n];

    long long inversions = mergeSortAndCount(arr, temp, 0, n - 1);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}