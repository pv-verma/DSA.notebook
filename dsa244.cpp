// Maximal Square (2D DP)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maximalSquare(vector<string>& g) {
    int m = g.size(), n = g[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));   // dp[i][j] = side of the biggest square ending at (i, j)
    int side = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '0') continue;

            if (i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

            side = max(side, dp[i][j]);
        }
    }
    return side * side;
}

int main() {
    vector<string> a = {"10100", "10111", "11111", "10010"};
    vector<string> b = {"01", "10"};
    vector<string> c = {"0"};

    cout << maximalSquare(a) << endl;
    cout << maximalSquare(b) << endl;
    cout << maximalSquare(c) << endl;
    return 0;
}