// Print a Matrix in Boundary (Perimeter) Order

#include <iostream>
#include <vector>
using namespace std;

vector<int> boundaryTraversal(vector<vector<int>>& matrix) {
    vector<int> result;
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (rows == 1) {
        // Special case: single row, just print it left to right
        for (int j = 0; j < cols; j++) result.push_back(matrix[0][j]);
        return result;
    }
    if (cols == 1) {
        // Special case: single column, just print it top to bottom
        for (int i = 0; i < rows; i++) result.push_back(matrix[i][0]);
        return result;
    }

    // Top row (left to right)
    for (int j = 0; j < cols; j++) result.push_back(matrix[0][j]);

    // Right column (top to bottom, excluding top-right corner already added)
    for (int i = 1; i < rows; i++) result.push_back(matrix[i][cols - 1]);

    // Bottom row (right to left, excluding bottom-right corner already added)
    for (int j = cols - 2; j >= 0; j--) result.push_back(matrix[rows - 1][j]);

    // Left column (bottom to top, excluding both corners already added)
    for (int i = rows - 2; i >= 1; i--) result.push_back(matrix[i][0]);

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = boundaryTraversal(matrix);

    cout << "Boundary elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}