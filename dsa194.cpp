//Longest Common Subsequence (2D DP)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    cout << lcs("abcde", "ace") << endl;
    cout << lcs("abc", "def") << endl;
    cout << lcs("AGGTAB", "GXTXAYB") << endl;
    return 0;
}