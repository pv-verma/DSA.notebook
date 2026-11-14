// Maximum Product Subarray (DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& a) {
    int mx = a[0], mn = a[0], best = a[0];

    for (int i = 1; i < a.size(); i++) {
        int x = a[i];
        if (x < 0) swap(mx, mn);       // a negative flips which product is biggest

        mx = max(x, mx * x);
        mn = min(x, mn * x);
        best = max(best, mx);
    }
    return best;
}

int main() {
    vector<int> a = {2, 3, -2, 4};
    vector<int> b = {-2, 0, -1};
    vector<int> c = {-2, 3, -4};

    cout << maxProduct(a) << endl;
    cout << maxProduct(b) << endl;
    cout << maxProduct(c) << endl;
    return 0;
}