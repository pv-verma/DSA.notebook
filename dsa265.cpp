// Longest Palindromic Subsequence (DP)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalSubseq(const string& s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));   // dp[i][j] = answer for s[i..j]

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << longestPalSubseq("bbbab") << endl;
    cout << longestPalSubseq("cbbd") << endl;
    cout << longestPalSubseq("agbdba") << endl;
    return 0;
}