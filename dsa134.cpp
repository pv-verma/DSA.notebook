// dynamic array using new and ddelete

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];   // dynamically allocate array of size n

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // pointer indexing works just like a normal array
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;   // free the allocated memory (IMPORTANT: use [] since it's an array)
    arr = nullptr;  // good practice: avoid dangling pointer

    return 0;
}