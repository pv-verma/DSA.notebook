#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid; // Update answer
            end = mid - 1; // Move left to find first occurrence
        } 
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        else if (key < arr[mid]) {
            end = mid - 1;
        }
    }
    return ans; // Return the index of first occurrence or -1 if not found
}

int lastOcc( int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid; // Update answer
            start = mid + 1; // Move right to find last occurrence
        } 
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        else if (key < arr[mid]) {
            end = mid - 1;
        }
    }
    return ans; // Return the index of last occurrence or -1 if not found
}

int main() {

    int even[6] = {2,4,6,6,6,18};
    
    int size = sizeof(even) / sizeof(even[0]); 


    int result = firstOcc(even, size, 6);
    cout << "First occurrence of 6 is at index: " << result << endl;
    int result2 = lastOcc(even, size, 6);
    cout << "Last occurrence of 6 is at index: " << result2 << endl;

    int numofOcc = (result2 - result) + 1;
    cout << "Number of occurrences of 6 is: " << numofOcc << endl;

    return 0;
}