//Array of Pointers vs Pointer to Array

#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3;

    // 1. Array of pointers: each slot holds the ADDRESS of a separate int
    int* arrOfPtrs[3] = {&a, &b, &c};

    cout << "Array of pointers:\n";
    for (int i = 0; i < 3; i++) {
        cout << "arrOfPtrs[" << i << "] points to value: " << *arrOfPtrs[i] << endl;
    }

    cout << endl;

    // 2. Pointer to an array: a single pointer referring to a whole array block
    int arr[3] = {10, 20, 30};
    int (*ptrToArr)[3] = &arr;   // note the parentheses -- crucial!

    cout << "Pointer to array:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Element " << i << ": " << (*ptrToArr)[i] << endl;
    }

    return 0;
}