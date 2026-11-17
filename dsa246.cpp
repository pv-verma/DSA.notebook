// Second Largest Element (No Sorting)

#include <iostream>
#include <climits>
using namespace std;

int secondLargest(int arr[], int n) {
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res = secondLargest(arr, n);
    if (res == INT_MIN) cout << "No second largest" << endl;
    else cout << res << endl;
    return 0;
}