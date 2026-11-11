// 3Sum (Sort and Two Pointers)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> a) {
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    int n = a.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;   // skip repeated first value

        int l = i + 1, r = n - 1;
        while (l < r) {
            int s = a[i] + a[l] + a[r];
            if (s == 0) {
                res.push_back({a[i], a[l], a[r]});
                l++;
                r--;
                while (l < r && a[l] == a[l - 1]) l++;   // skip repeated second value
            }
            else if (s < 0) l++;
            else r--;
        }
    }
    return res;
}

int main() {
    for (auto& t : threeSum({-1, 0, 1, 2, -1, -4})) {
        cout << t[0] << " " << t[1] << " " << t[2] << endl;
    }
    return 0;
}