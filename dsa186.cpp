// Longest Increasing Subsequence (DP with Binary Search)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;   // tails[i] = smallest tail of any increasing run of length i+1

    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);   // x extends the longest run
        else *it = x;                                // x makes an existing run end smaller
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "LIS length: " << lengthOfLIS(nums) << endl;
    return 0;
}