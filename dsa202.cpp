// Count Set Bits for Every Number 0 to n (Bit Manipulation + DP)

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);   // drop the last bit, then add it back if it was 1
    }
    return dp;
}

int main() {
    vector<int> res = countBits(5);

    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}