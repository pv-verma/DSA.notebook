// wave print

#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int nCols) {
    vector<int> ans;

    for (int col = 0; col < nCols; col++) {

        if (col & 1) {
            // odd column index -> bottom to top
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        else {
            // even column index -> top to bottom
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int nRows = arr.size();
    int nCols = arr[0].size();

    vector<int> result = wavePrint(arr, nRows, nCols);

    cout << "Wave print: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}