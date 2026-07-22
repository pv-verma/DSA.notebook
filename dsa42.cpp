#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size -1;

    int mid = start + (end - start) / 2;

    while (start <= end) {

        if (arr[mid] == key) {
            return mid;
        }

        if (key > arr[mid]) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1; // Return -1 if element is not found
}

int main() {
    
    int even[] = {2,4,6,8,12,18};
    int odd[] = {3,8,9,11,14};
    
    int even_index = binarySearch(even, 6, 12);
    if (even_index != -1) {
        cout << "Element found at index: " << even_index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    int odd_index = binarySearch(odd, 5, 11);
    if (odd_index != -1) {
        cout << "Element found at index: " << odd_index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}