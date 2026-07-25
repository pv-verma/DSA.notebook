#include <iostream>
using namespace std;

//search in rotated sorted array

int search(int arr[], int n, int target) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;

        // left half is sorted
        if (arr[start] <= arr[mid]) {
            if (target >= arr[start] && target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        // right half is sorted
        else {
            if (target > arr[mid] && target <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    
    int target = 0;
    cout << "Index: " << search(arr, 7, target) << endl;
    return 0;
}