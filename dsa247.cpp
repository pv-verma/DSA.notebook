// Move All Zeroes to the End

#include <iostream>
#include <utility>
using namespace std;

void moveZeroes(int arr[], int n) {
    int write = 0;                       // next slot for a non-zero value

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[write], arr[i]);
            write++;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}