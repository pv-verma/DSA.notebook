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
    
    if (second == INT_MIN) {
        cout << "No second largest element exists" << endl;
        return -1;
    }
    
    return second;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = 6;
    cout << "Second largest: " << secondLargest(arr, n) << endl;
    system("pause");
    return 0;
}