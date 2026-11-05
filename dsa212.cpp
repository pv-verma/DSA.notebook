// Segment Tree for Range Sum with Point Update

#include <iostream>
#include <vector>
using namespace std;

class SegTree {
    int n;
    vector<int> t;

public:
    SegTree(vector<int>& a) : n(a.size()), t(2 * a.size()) {
        for (int i = 0; i < n; i++) t[n + i] = a[i];          // leaves
        for (int i = n - 1; i >= 1; i--) t[i] = t[2 * i] + t[2 * i + 1];
    }

    void update(int i, int value) {
        i += n;
        t[i] = value;
        for (; i > 1; i >>= 1) t[i >> 1] = t[i] + t[i ^ 1];   // i ^ 1 is the sibling
    }

    int query(int l, int r) {                                 // sum of [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegTree st(a);

    cout << "Sum [1, 4): " << st.query(1, 4) << endl;   // 3 + 5 + 7
    st.update(1, 10);
    cout << "After update: " << st.query(1, 4) << endl; // 10 + 5 + 7
    return 0;
}