// insert interval

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& iv, vector<int> nw) {
    vector<vector<int>> res;
    int i = 0, n = iv.size();

    // phase 1: intervals that end before the new one starts
    while (i < n && iv[i][1] < nw[0]) {
        res.push_back(iv[i++]);
    }

    // phase 2: intervals that overlap the new one, absorb them
    while (i < n && iv[i][0] <= nw[1]) {
        nw[0] = min(nw[0], iv[i][0]);
        nw[1] = max(nw[1], iv[i][1]);
        i++;
    }
    res.push_back(nw);

    // phase 3: intervals that start after the new one ends
    while (i < n) {
        res.push_back(iv[i++]);
    }
    return res;
}

void print(vector<vector<int>>& v) {
    for (auto& x : v) cout << "[" << x[0] << "," << x[1] << "] ";
    cout << endl;
}

int main() {
    vector<vector<int>> a = {{1, 3}, {6, 9}};
    vector<vector<int>> b = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

    auto r1 = insertInterval(a, {2, 5});
    auto r2 = insertInterval(b, {4, 8});

    print(r1);
    print(r2);
    return 0;
}