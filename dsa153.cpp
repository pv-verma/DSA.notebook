#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter initial size: ";
    cin >> size;

    // 1. Create a dynamic array of original size
    int* arr = new int[size];

    cout << "Enter " << size << " numbers: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    
    // 2. Create a NEW dynamic array that is TWICE the size
    int newSize = size * 2;
    int* temp = new int[newSize]; // Allocated larger memory block on Heap

    // 3. Copy elements from the old 'arr' into the new 'temp' array
    for(int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    // 4. CRITICAL: Free the memory of the OLD small array to prevent a memory leak
    delete[] arr; 

    // 5. Point the 'arr' pointer to the new 'temp' array
    arr = temp;
    size = newSize;

    
    // Taking input for the newly added space
    cout << "Enter " << size / 2 << " more numbers: ";
    for(int i = size / 2; i < size; i++) {
        cin >> arr[i];
    }

    // Display final array
    cout << "Final array elements: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 6. Clean up the final allocated memory before exiting
    delete[] arr;

    return 0;
}
