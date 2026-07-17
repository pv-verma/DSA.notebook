#include <iostream>
using namespace std;

// finding pair sum

int main() {
    int arr[] = {1, 2, 3, 4, 5,2, 8, -1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 7;

    cout << "Pairs with sum " << targetSum << " are: ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == targetSum) {
                cout << "(" << arr[i] << ", " << arr[j] << ") ";
            }
        }
    }
    cout << endl;

    return 0;
}