// First and Last Position of a Target (STL Binary Search)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    auto lo = lower_bound(nums.begin(), nums.end(), target);   // first element >= target

    if (lo == nums.end() || *lo != target) return {-1, -1};

    auto hi = upper_bound(nums.begin(), nums.end(), target);   // first element > target

    return {int(lo - nums.begin()), int(hi - nums.begin()) - 1};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};

    vector<int> a = searchRange(nums, 8);
    vector<int> b = searchRange(nums, 6);

    cout << a[0] << " " << a[1] << endl;
    cout << b[0] << " " << b[1] << endl;
    return 0;
}