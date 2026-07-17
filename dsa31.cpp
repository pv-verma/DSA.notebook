#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int n) {
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
}

int main() {

    int even[8] = {2, 4, 6, 8, 10, 12, 14, 16};
    int odd[5] = {1, 3, 5, 4, 9};


    swapAlternate(even, 8);
    printArray(even, 8);
    swapAlternate(odd, 5);
    printArray(odd, 5);

    return 0;
}
