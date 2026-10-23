// Product of Array Except Self (Arrays)

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        res[i] = prefix;              // product of everything left of i
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffix;             // multiply in everything right of i
        suffix *= nums[i];
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);

    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}