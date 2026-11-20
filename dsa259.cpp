// Rod Cutting (Unbounded DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCut(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);              // dp[len] = best price for a rod of that length

    for (int len = 1; len <= n; len++) {
        for (int cut = 1; cut <= len; cut++) {
            dp[len] = max(dp[len], price[cut - 1] + dp[len - cut]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> a = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> b = {3, 5, 8, 9, 10, 17, 17, 20};

    cout << rodCut(a, 8) << endl;
    cout << rodCut(b, 8) << endl;
    return 0;
}