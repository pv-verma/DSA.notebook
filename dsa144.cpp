// Check if a Matrix is Symmetric

#include <iostream>
#include <vector>
using namespace std;

bool isSymmetric(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {   // only check upper triangle
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {2, 5, 6},
        {3, 6, 9}
    };

    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "matrix1 symmetric? " << (isSymmetric(matrix1) ? "Yes" : "No") << endl;
    cout << "matrix2 symmetric? " << (isSymmetric(matrix2) ? "Yes" : "No") << endl;

    return 0;
}