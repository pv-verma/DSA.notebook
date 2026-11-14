// Container With Most Water (Two Pointers)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& h) {
    int l = 0, r = h.size() - 1, best = 0;

    while (l < r) {
        best = max(best, min(h[l], h[r]) * (r - l));
        if (h[l] < h[r]) l++;      // the shorter wall limits the area, so move it
        else r--;
    }
    return best;
}

int main() {
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> b = {1, 1};

    cout << maxArea(a) << endl;
    cout << maxArea(b) << endl;
    return 0;
}