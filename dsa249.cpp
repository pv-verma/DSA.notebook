// Counting Sort (With Negative Numbers)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& a) {
    if (a.empty()) return;

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    vector<int> count(mx - mn + 1, 0);
    for (int x : a) count[x - mn]++;          // shift so the smallest value maps to index 0

    int idx = 0;
    for (int v = 0; v < (int)count.size(); v++) {
        while (count[v]-- > 0) a[idx++] = v + mn;
    }
}

int main() {
    vector<int> a = {4, 2, 2, 8, 3, 3, 1, -1};
    countingSort(a);

    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}