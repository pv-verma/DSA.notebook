// Knapsack (DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    vector<int> dp(W + 1, 0);   // dp[c] = best value with capacity c

    for (int i = 0; i < wt.size(); i++) {
        for (int c = W; c >= wt[i]; c--) {          // backwards, so item i is used once
            dp[c] = max(dp[c], dp[c - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    vector<int> wt1 = {1, 3, 4, 5}, val1 = {1, 4, 5, 7};
    vector<int> wt2 = {10, 20, 30}, val2 = {60, 100, 120};

    cout << knapsack(wt1, val1, 7) << endl;
    cout << knapsack(wt2, val2, 50) << endl;
    return 0;
}