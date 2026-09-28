// Count Elements Using Pointer Subtraction

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};

    int* start = &arr[1];   // points to 20
    int* end = &arr[5];     // points to 60

    int count = end - start;   // pointer subtraction gives number of elements between them

    cout << "Elements from index 1 to index 5 (exclusive): " << count << endl;

    cout << "Values in that range: ";
    for (int* ptr = start; ptr < end; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}