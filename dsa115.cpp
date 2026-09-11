// Search in a Row-Wise and Column-Wise Sorted Matrix

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = cols - 1;   // start at top-right corner

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        }
        else if (matrix[row][col] > target) {
            col--;   // eliminate this column, move left
        }
        else {
            row++;   // eliminate this row, move down
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  4,  7,  11},
        {2,  5,  8,  12},
        {3,  6,  9,  16},
        {10, 13, 14, 17}
    };

    int target1 = 5;
    int target2 = 15;

    cout << "Search " << target1 << ": " << (searchMatrix(matrix, target1) ? "Found" : "Not Found") << endl;
    cout << "Search " << target2 << ": " << (searchMatrix(matrix, target2) ? "Found" : "Not Found") << endl;

    return 0;
}