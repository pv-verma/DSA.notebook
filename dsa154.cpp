// Pointers vs References

#include <iostream>
using namespace std;

void modifyWithPointer(int* ptr) {
    if (ptr != nullptr) {   // pointers CAN be null, so must check
        *ptr = *ptr + 10;    // must dereference explicitly
    }
}

void modifyWithReference(int& ref) {
    ref = ref + 10;   // no dereferencing needed, acts just like a normal variable
    // ref can NEVER be null -- the language guarantees it refers to something
}

int main() {
    int x = 5, y = 100;

    // --- Pointer behavior ---
    int* ptr = &x;
    modifyWithPointer(ptr);
    cout << "x after pointer modification: " << x << endl;

    ptr = &y;          // pointers CAN be reseated (point to a different variable later)
    cout << "ptr now points to y: " << *ptr << endl;

    // --- Reference behavior ---
    int& ref = x;
    modifyWithReference(ref);
    cout << "x after reference modification: " << x << endl;

    // ref = y;   // This does NOT make ref refer to y!
                   // It actually copies y's VALUE into x (since ref IS x, permanently)
    ref = y;
    cout << "x after 'ref = y' (NOT a reseat, this is assignment): " << x << endl;
    cout << "y is unchanged: " << y << endl;

    return 0;
}