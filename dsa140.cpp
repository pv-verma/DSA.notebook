// Detect if a Pointer is nullptr Before Dereferencing (Safe Pointer Usage)

#include <iostream>
using namespace std;

bool safeGetValue(int* ptr, int& result) {
    if (ptr == nullptr) {
        return false;   // signal failure, don't touch result
    }
    result = *ptr;
    return true;
}

int main() {
    int x = 42;
    int* validPtr = &x;
    int* nullPtr = nullptr;

    int result;

    if (safeGetValue(validPtr, result)) {
        cout << "Valid pointer value: " << result << endl;
    } else {
        cout << "Pointer was null, cannot dereference" << endl;
    }

    if (safeGetValue(nullPtr, result)) {
        cout << "Null pointer value: " << result << endl;
    } else {
        cout << "Pointer was null, cannot dereference" << endl;
    }

    return 0;
}