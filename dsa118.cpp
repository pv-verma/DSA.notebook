// Find the Row with Maximum Number of 1s (Sorted Binary Matrix)

#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = cols - 1;   // start at top-right
    int ansRow = -1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == 1) {
            ansRow = row;   // this row has a 1 at this column
            col--;          // check if there are more 1s to the left
        } else {
            row++;          // no 1 here, move to next row
        }
    }

    return ansRow;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMax1s(matrix);

    if (result != -1)
        cout << "Row with max 1s: " << result << endl;
    else
        cout << "No 1s found in the matrix" << endl;

    return 0;
}