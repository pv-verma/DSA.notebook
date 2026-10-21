// Minimum Coins for an Amount (Dynamic Programming)

#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);   // amount + 1 acts as "infinity"
    dp[0] = 0;

    for (int a = 1; a <= amount; a++) {
        for (int c : coins) {
            if (c <= a) {
                dp[a] = min(dp[a], dp[a - c] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins1 = {1, 2, 5};
    vector<int> coins2 = {2};

    cout << coinChange(coins1, 11) << endl;
    cout << coinChange(coins2, 3) << endl;
    return 0;
}