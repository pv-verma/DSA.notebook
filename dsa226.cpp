// Minimum Size Subarray With Sum at Least Target (Sliding Window)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minSubArrayLen(int target, vector<int>& a) {
    int left = 0, sum = 0, best = INT_MAX;

    for (int right = 0; right < a.size(); right++) {
        sum += a[right];

        while (sum >= target) {
            best = min(best, right - left + 1);
            sum -= a[left++];
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main() {
    vector<int> a = {2, 3, 1, 2, 4, 3};
    vector<int> b = {1, 1, 1, 1};

    cout << minSubArrayLen(7, a) << endl;
    cout << minSubArrayLen(11, b) << endl;
    return 0;
}