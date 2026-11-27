// Number of Unique BSTs

#include <iostream>
#include <vector>
using namespace std;

long long numTrees(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;                                   // the empty tree counts as one shape

    for (int nodes = 1; nodes <= n; nodes++) {
        for (int root = 1; root <= nodes; root++) {
            dp[nodes] += dp[root - 1] * dp[nodes - root];   // left size times right size
        }
    }
    return dp[n];
}

int main() {
    int tests[] = {1, 3, 4, 10};
    for (int n : tests) cout << "n = " << n << ": " << numTrees(n) << endl;
    return 0;
}