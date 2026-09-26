// Multiply Two Matrices

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size();
    int n = A[0].size();     // must equal B.size() for valid multiplication
    int p = B[0].size();

    vector<vector<int>> C(m, vector<int>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    if (A[0].size() != B.size()) {
        cout << "Matrices cannot be multiplied (dimension mismatch)" << endl;
        return 1;
    }

    vector<vector<int>> C = multiplyMatrices(A, B);

    cout << "Result of A x B:\n";
    printMatrix(C);

    return 0;
}