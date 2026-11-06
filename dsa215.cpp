// Permutations With Duplicates (Backtracking)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& cur,
               vector<vector<int>>& res) {
    if (cur.size() == nums.size()) {
        res.push_back(cur);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        // skip a repeated value unless its earlier twin is already in use
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        cur.push_back(nums[i]);
        backtrack(nums, used, cur, res);
        cur.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> nums) {
    sort(nums.begin(), nums.end());       // equal values must sit next to each other
    vector<vector<int>> res;
    vector<bool> used(nums.size(), false);
    vector<int> cur;
    backtrack(nums, used, cur, res);
    return res;
}

int main() {
    for (auto& p : permuteUnique({1, 1, 2})) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }
    return 0;
}