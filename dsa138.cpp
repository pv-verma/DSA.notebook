// Find Maximum Element Using Pointers Only (No Indexing)

#include <iostream>
using namespace std;

int findMax(int* start, int* end) {
    int maxVal = *start;   // assume first element is max initially

    for (int* ptr = start; ptr != end; ptr++) {
        if (*ptr > maxVal) {
            maxVal = *ptr;
        }
    }

    return maxVal;
}

int main() {
    int arr[] = {3, 7, 2, 9, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = findMax(arr, arr + n);   // arr+n = one-past-the-last element

    cout << "Maximum element: " << maxVal << endl;

    return 0;
}