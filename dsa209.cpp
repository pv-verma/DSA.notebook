// Partition Equal Subset Sum (Subset DP)

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;         // an odd total can never split evenly

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;                             // empty subset sums to 0

    for (int x : nums) {
        for (int s = target; s >= x; s--) {   // backwards so each number is used once
            if (dp[s - x]) dp[s] = true;
        }
    }
    return dp[target];
}

int main() {
    vector<int> a = {1, 5, 11, 5};
    vector<int> b = {1, 2, 3, 5};

    cout << (canPartition(a) ? "Yes" : "No") << endl;
    cout << (canPartition(b) ? "Yes" : "No") << endl;
    return 0;
}