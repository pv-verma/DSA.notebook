// Set Matrix Zeroes (In-Place)

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // Check if first row/col originally contain a zero
    for (int j = 0; j < cols; j++)
        if (matrix[0][j] == 0) firstRowHasZero = true;

    for (int i = 0; i < rows; i++)
        if (matrix[i][0] == 0) firstColHasZero = true;

    // Use first row/col as markers for the rest of the matrix
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;   // mark row
                matrix[0][j] = 0;   // mark column
            }
        }
    }

    // Zero out cells based on markers (skip first row/col for now)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Finally, handle first row and first column
    if (firstRowHasZero) {
        for (int j = 0; j < cols; j++) matrix[0][j] = 0;
    }
    if (firstColHasZero) {
        for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original:\n";
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "After setting zeroes:\n";
    printMatrix(matrix);

    return 0;
}