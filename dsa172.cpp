// All Subsets of an Array (Recursion and Backtracking)

#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int>& cur) {
    cout << "[";
    for (int k = 0; k < cur.size(); k++) {
        if (k) cout << " ";
        cout << cur[k];
    }
    cout << "]" << endl;
}

void backtrack(vector<int>& nums, int start, vector<int>& cur) {
    printSubset(cur);   // every path through the recursion is a valid subset

    for (int i = start; i < nums.size(); i++) {
        cur.push_back(nums[i]);        // choose
        backtrack(nums, i + 1, cur);   // explore
        cur.pop_back();                // undo the choice
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> cur;

    backtrack(nums, 0, cur);

    return 0;
}