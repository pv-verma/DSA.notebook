// N-Queens Count (Backtracking)

#include <iostream>
#include <vector>
using namespace std;

void solve(int row, int n, vector<bool>& cols, vector<bool>& d1,
           vector<bool>& d2, int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (cols[c] || d1[row - c + n - 1] || d2[row + c]) continue;

        cols[c] = d1[row - c + n - 1] = d2[row + c] = true;   // place
        solve(row + 1, n, cols, d1, d2, count);
        cols[c] = d1[row - c + n - 1] = d2[row + c] = false;  // undo
    }
}

int countQueens(int n) {
    vector<bool> cols(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
    int count = 0;
    solve(0, n, cols, d1, d2, count);
    return count;
}

int main() {
    cout << countQueens(4) << endl;
    cout << countQueens(6) << endl;
    cout << countQueens(8) << endl;
    return 0;
}