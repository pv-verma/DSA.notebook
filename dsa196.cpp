// Jump Game (Greedy)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;          // stuck before reaching index i
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> a = {2, 3, 1, 1, 4};
    vector<int> b = {3, 2, 1, 0, 4};

    cout << (canJump(a) ? "Yes" : "No") << endl;
    cout << (canJump(b) ? "Yes" : "No") << endl;
    return 0;
}