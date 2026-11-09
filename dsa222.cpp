// Coin Change, Number of Ways (DP)

#include <iostream>
#include <vector>
using namespace std;

long long countWays(vector<int>& coins, int amount) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;                                   // one way to make 0: use nothing

    for (int c : coins) {                        // coins in the OUTER loop
        for (int a = c; a <= amount; a++) {
            dp[a] += dp[a - c];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};

    cout << countWays(coins, 5) << endl;
    cout << countWays(coins, 11) << endl;
    return 0;
}