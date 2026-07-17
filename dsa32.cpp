#include <iostream>
using namespace std;

// finding unique element in an array where all elements except one are present twice

int findUnique(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    int arr[7] = {1, 2, 3, 4, 3, 2, 1};
    cout << "The unique element is: " << findUnique(arr, 7) << endl;
    return 0;
}