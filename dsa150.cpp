// Void Pointers (Generic Pointers)

#include <iostream>
using namespace std;

int main() {
    int i = 42;
    double d = 3.14;
    char c = 'A';

    void* vptr;   // generic pointer, can hold address of ANY type

    // Point to an int
    vptr = &i;
    cout << "Int value: " << *(static_cast<int*>(vptr)) << endl;

    // Point to a double
    vptr = &d;
    cout << "Double value: " << *(static_cast<double*>(vptr)) << endl;

    // Point to a char
    vptr = &c;
    cout << "Char value: " << *(static_cast<char*>(vptr)) << endl;

    return 0;
}