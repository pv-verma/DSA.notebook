//   Swap Two Pointers (Not the Values They Point To)

#include <iostream>
using namespace std;

void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapPointers(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int* p1 = &x;
    int* p2 = &y;

    cout << "Before:\n";
    cout << "x = " << x << ", y = " << y << endl;
    cout << "p1 points to: " << *p1 << ", p2 points to: " << *p2 << endl;

    swapPointers(&p1, &p2);   // now p1 points to y, p2 points to x

    cout << "\nAfter swapPointers:\n";
    cout << "x = " << x << ", y = " << y << " (unchanged!)" << endl;
    cout << "p1 points to: " << *p1 << ", p2 points to: " << *p2 << " (swapped!)" << endl;

    return 0;
}