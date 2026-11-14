// Find a Peak Element (Binary Search on a Slope)

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int>& a) {
    int lo = 0, hi = a.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < a[mid + 1]) lo = mid + 1;   // slope goes up, a peak exists to the right
        else hi = mid;                           // slope goes down, mid itself could be the peak
    }
    return lo;
}

int main() {
    vector<int> a = {1, 2, 3, 1};
    vector<int> b = {1, 2, 1, 3, 5, 6, 4};

    cout << findPeak(a) << endl;
    cout << findPeak(b) << endl;
    return 0;
}