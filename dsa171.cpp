// Generate an n x n Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateSpiral(int n) {
    vector<vector<int>> m(n, vector<int>(n));

    int top = 0, bottom = n - 1;
    int lc = 0, rc = n - 1;
    int val = 1;

    while (top <= bottom && lc <= rc) {
        for (int j = lc; j <= rc; j++) m[top][j] = val++;
        top++;

        for (int i = top; i <= bottom; i++) m[i][rc] = val++;
        rc--;

        if (top <= bottom) {
            for (int j = rc; j >= lc; j--) m[bottom][j] = val++;
            bottom--;
        }

        if (lc <= rc) {
            for (int i = bottom; i >= top; i--) m[i][lc] = val++;
            lc++;
        }
    }
    return m;
}

int main() {
    vector<vector<int>> m = generateSpiral(3);

    for (auto& row : m) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}