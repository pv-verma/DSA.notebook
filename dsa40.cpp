#include <iostream>
using namespace std;

// Find the Largest and Smallest Element in an Array

int main() {
    int arr[] = {3, 1, 7, 2, 9, 4};
    int n = 6;
    int maxVal = arr[0], minVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;
    return 0;
}