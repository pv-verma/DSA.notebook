// Pointer Arithmetic with a 2D Array

#include <iostream>
using namespace std;

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int rows = 3, cols = 4;

    // arr decays to a pointer to its first row: int (*ptr)[4]
    int (*ptr)[4] = arr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // *(ptr + i) gives the i-th row (as int*), then + j moves to column j
            cout << *(*(ptr + i) + j) << " ";
        }
        cout << endl;
    }

    return 0;
}