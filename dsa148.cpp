// const Pointers (Three Different Meanings)


#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 20;

    // 1. Pointer to CONST int: the VALUE can't change through this pointer,
    //    but the pointer itself CAN be redirected to point elsewhere
    const int* ptr1 = &x;
    // *ptr1 = 100;      // ERROR: can't modify value through ptr1
    ptr1 = &y;           // OK: can repoint ptr1
    cout << "ptr1 now points to: " << *ptr1 << endl;

    // 2. CONST pointer to int: the pointer itself CANNOT be redirected,
    //    but the VALUE it points to CAN be changed
    int* const ptr2 = &x;
    *ptr2 = 100;          // OK: can modify value through ptr2
    // ptr2 = &y;         // ERROR: can't repoint ptr2, it's locked to x
    cout << "ptr2 modified x to: " << x << endl;

    // 3. CONST pointer to CONST int: neither the pointer NOR the value can change
    const int* const ptr3 = &y;
    // *ptr3 = 50;        // ERROR: can't modify value
    // ptr3 = &x;         // ERROR: can't repoint
    cout << "ptr3 permanently points to: " << *ptr3 << endl;

    return 0;
}