#include <iostream>
using namespace std;

// finding pivot in an sorted and rotated array using binary search

int findPivot(int arr[], int n) {
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {

        if (arr[mid] >= arr[0]) {
            s = mid + 1; // Move right
        } 
        else {
            e = mid; // Move left
        }
        mid = s + (e - s) / 2;
    }
    return s; 
}

int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    
    cout << "Pivot index is " << findPivot(arr, 7)<<endl;
    
    return 0;
}