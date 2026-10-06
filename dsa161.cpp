//  Resizable Dynamic Array (Simulating How vector Grows Internally)

#include <iostream>
using namespace std;

int main() {
    // Simulating a simple resizable dynamic array
    int* arr = new int[5];  // Initial size
    int size = 5;
    int capacity = 5;

    // Adding elements (simulating vector behavior)
    for (int i = 0; i < 10; i++) {
        if (size >= capacity) {
            // Resize the array (simulate vector growth)
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int j = 0; j < size; j++) {
                newArr[j] = arr[j];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = i;
    }

    // Output the array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Cleanup
    delete[] arr;

    return 0;
}