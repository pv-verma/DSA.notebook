// Combination Sum (Backtracking With Reuse)

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& c, int start, int remaining,
               vector<int>& cur, vector<vector<int>>& res) {
    if (remaining == 0) {
        res.push_back(cur);
        return;
    }

    for (int i = start; i < c.size(); i++) {
        if (c[i] > remaining) continue;

        cur.push_back(c[i]);
        backtrack(c, i, remaining - c[i], cur, res);   // pass i, not i + 1, to allow reuse
        cur.pop_back();
    }
}

int main() {
    vector<int> c = {2, 3, 6, 7};
    vector<vector<int>> res;
    vector<int> cur;

    backtrack(c, 0, 7, cur, res);

    for (auto& comb : res) {
        for (int x : comb) cout << x << " ";
        cout << endl;
    }
    return 0;
}