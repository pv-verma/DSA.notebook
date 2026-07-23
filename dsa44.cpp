#include <iostream>
using namespace std;

// peak index in mountain array

int peakIndex(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start < end) {

        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1; // Move right
        } 
        else {
            end = mid; // Move left
        }
        mid = start + (end - start) / 2;
    }
    
    return start; // or return end, both are same at the end of loop
}

int main() {

    int odd[] = {1,3,5,7,6,4,0};

    cout << "Peak index is " << peakIndex(odd,7);


    return 0;

}