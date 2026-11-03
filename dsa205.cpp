// Trapping Rain Water (Two Pointers)

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& h) {
    int l = 0, r = h.size() - 1;
    int lmax = 0, rmax = 0, water = 0;

    while (l < r) {
        if (h[l] < h[r]) {
            if (h[l] >= lmax) lmax = h[l];
            else water += lmax - h[l];
            l++;
        } else {
            if (h[r] >= rmax) rmax = h[r];
            else water += rmax - h[r];
            r--;
        }
    }
    return water;
}

int main() {
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> b = {4, 2, 0, 3, 2, 5};

    cout << trap(a) << endl;
    cout << trap(b) << endl;
    return 0;
}