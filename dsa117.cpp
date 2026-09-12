// Print a Matrix in Diagonal Order (Zigzag Diagonals)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> result;

    // There are (rows + cols - 1) diagonals total
    for (int d = 0; d < rows + cols - 1; d++) {
        vector<int> intermediate;

        // Determine starting cell of this diagonal
        int r = (d < cols) ? 0 : d - cols + 1;
        int c = (d < cols) ? d : cols - 1;

        // Traverse this diagonal (moving down-left: row++, col--)
        while (r < rows && c >= 0) {
            intermediate.push_back(matrix[r][c]);
            r++;
            c--;
        }

        // Reverse every alternate diagonal for the zigzag effect
        if (d % 2 == 0) {
            reverse(intermediate.begin(), intermediate.end());
        }

        for (int val : intermediate) {
            result.push_back(val);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = findDiagonalOrder(matrix);

    cout << "Diagonal zigzag order: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}