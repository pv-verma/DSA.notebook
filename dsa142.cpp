// spiral print

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> arr, int nRows, int nCols) {
    vector<int> ans;

    int total = nRows * nCols;
    int count = 0;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = nRows - 1;
    int endingCol = nCols - 1;

    while (count < total) {

        // print starting row (left to right)
        for (int index = startingCol; count < total && index <= endingCol; index++) {
            ans.push_back(arr[startingRow][index]);
            count++;
        }
        startingRow++;

        // print ending column (top to bottom)
        for (int index = startingRow; count < total && index <= endingRow; index++) {
            ans.push_back(arr[index][endingCol]);
            count++;
        }
        endingCol--;

        // print ending row (right to left)
        for (int index = endingCol; count < total && index >= startingCol; index--) {
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;

        // print starting column (bottom to top)
        for (int index = endingRow; count < total && index >= startingRow; index--) {
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int nRows = arr.size();
    int nCols = arr[0].size();

    vector<int> result = spiralPrint(arr, nRows, nCols);

    cout << "Spiral print: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}