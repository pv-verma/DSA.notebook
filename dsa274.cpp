// Candy Distribution (Two-Pass Greedy)

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int candy(vector<int>& r) {
    int n = r.size();
    vector<int> c(n, 1);

    for (int i = 1; i < n; i++) {                 // satisfy the left neighbor
        if (r[i] > r[i - 1]) c[i] = c[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {            // satisfy the right neighbor, keep the left result
        if (r[i] > r[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
    }
    return accumulate(c.begin(), c.end(), 0);
}

int main() {
    vector<int> a = {1, 0, 2};
    vector<int> b = {1, 2, 2};
    vector<int> c = {1, 3, 2, 2, 1};

    cout << candy(a) << endl;
    cout << candy(b) << endl;
    cout << candy(c) << endl;
    return 0;
}