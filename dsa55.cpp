#include <iostream>
using namespace std;

// Function to count inversions in an array using insertion sort
int countInversions(int arr[], int n) {
    int count = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            count++;   // each shift = one inversion
        }
        arr[j + 1] = key;
    }

    return count;
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

    int inversions = countInversions(arr,n);

    cout << endl;
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}