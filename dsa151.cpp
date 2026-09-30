#include <iostream>
using namespace std;

int* createDanglingPointer() {
    int localVar = 100;
    return &localVar;   // DANGER: returning address of a local variable
}   // localVar is destroyed here, the moment the function returns

int main() {
    // Example 1: dangling pointer from a function returning a local's address
    int* ptr1 = createDanglingPointer();
    cout << "Dangling pointer (undefined behavior): " << *ptr1 << endl;
    // ^ This MAY print 100 by luck, or garbage, or crash -- it's undefined behavior

    // Example 2: dangling pointer after delete
    int* ptr2 = new int(42);
    cout << "Before delete: " << *ptr2 << endl;

    delete ptr2;   // memory freed, butg