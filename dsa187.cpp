// Minimum Eating Speed (Binary Search on the Answer)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 1;
    int hi = *max_element(piles.begin(), piles.end());

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        long long hours = 0;
        for (int p : piles) hours += (p + mid - 1) / mid;   // ceil(p / mid)

        if (hours <= h) hi = mid;      // mid works, try slower
        else lo = mid + 1;             // too slow, need faster
    }
    return lo;
}

int main() {
    vector<int> a = {3, 6, 7, 11};
    vector<int> b = {30, 11, 23, 4, 20};

    cout << minEatingSpeed(a, 8) << endl;
    cout << minEatingSpeed(b, 5) << endl;
    cout << minEatingSpeed(b, 6) << endl;
    return 0;
}