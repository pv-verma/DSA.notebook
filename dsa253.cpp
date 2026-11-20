// Valid Sudoku Board

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValidSudoku(vector<string>& b) {
    int row[9] = {0}, col[9] = {0}, box[9] = {0};   // one bitmask per row, column and box

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (b[i][j] == '.') continue;

            int bit = 1 << (b[i][j] - '1');
            int k = (i / 3) * 3 + j / 3;             // which box this cell is in

            if ((row[i] & bit) || (col[j] & bit) || (box[k] & bit)) return false;

            row[i] |= bit;
            col[j] |= bit;
            box[k] |= bit;
        }
    }
    return true;
}

int main() {
    vector<string> board = {
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    };

    vector<string> bad = board;
    bad[0][0] = '8';                                  // clashes with the 8 in column 0

    cout << (isValidSudoku(board) ? "Valid" : "Invalid") << endl;
    cout << (isValidSudoku(bad) ? "Valid" : "Invalid") << endl;
    return 0;
}