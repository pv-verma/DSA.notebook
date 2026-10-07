// Handling Allocation Failure (new Throwing bad_alloc)

#include <iostream>
#include <new>       // required for std::bad_alloc and std::nothrow
using namespace std;

int main() {
    size_t hugeSize = static_cast<size_t>(-1) / sizeof(int);

    // Approach 1: let new throw, and catch the exception
    try {
        // Requesting an absurdly large amount of memory to force a failure
        int* hugeArray = new int[hugeSize];
        delete[] hugeArray;   // unreachable if the allocation above fails
    }
    catch (const bad_alloc& e) {
        cout << "Allocation failed (exception caught): " << e.what() << endl;
    }

    // Approach 2: nothrow version -- returns nullptr instead of throwing
    int* ptr = new(nothrow) int[hugeSize];

    if (ptr == nullptr) {
        cout << "Allocation failed (nullptr returned, nothrow version)" << endl;
    } else {
        cout << "Allocation succeeded" << endl;
        delete[] ptr;
    }

    // A normal, small, successful allocation for comparison
    int* small = new(nothrow) int(5);
    if (small != nullptr) {
        cout << "Small allocation succeeded: " << *small << endl;
        delete small;
    }

    return 0;
}