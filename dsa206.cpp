// Edit Distance (String DP)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;   // delete all i characters
    for (int j = 0; j <= n; j++) dp[0][j] = j;   // insert all j characters

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],        // delete from a
                                    dp[i][j - 1],        // insert into a
                                    dp[i - 1][j - 1]});  // replace
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << editDistance("horse", "ros") << endl;
    cout << editDistance("intention", "execution") << endl;
    return 0;
}