// House Robber (1D DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int prev2 = 0;   // best total up to two houses back
    int prev1 = 0;   // best total up to the previous house

    for (int x : nums) {
        int cur = max(prev1, prev2 + x);   // skip this house, or take it
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    vector<int> a = {2, 7, 9, 3, 1};
    vector<int> b = {1, 2, 3, 1};

    cout << rob(a) << endl;
    cout << rob(b) << endl;
    return 0;
}