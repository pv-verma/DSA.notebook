// Unique Paths With Obstacles (Grid DP)

#include <iostream>
#include <vector>
using namespace std;

long long uniquePaths(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    if (g[0][0] == 1 || g[m - 1][n - 1] == 1) return 0;

    vector<long long> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) dp[j] = 0;          // blocked cell, no way to stand here
            else if (j > 0) dp[j] += dp[j - 1];   // from above (old dp[j]) plus from left
        }
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> a = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> b = {{0, 1}, {0, 0}};

    cout << uniquePaths(a) << endl;
    cout << uniquePaths(b) << endl;
    return 0;
}