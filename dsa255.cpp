// Radix Sort (LSD)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countByDigit(vector<int>& a, long long exp) {
    int n = a.size();
    vector<int> out(n);
    int cnt[10] = {0};

    for (int x : a) cnt[(x / exp) % 10]++;
    for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];       // cnt[d] = end position for digit d

    for (int i = n - 1; i >= 0; i--) {                        // backwards keeps each pass stable
        out[--cnt[(a[i] / exp) % 10]] = a[i];
    }
    a = out;
}

void radixSort(vector<int>& a) {
    if (a.empty()) return;
    int mx = *max_element(a.begin(), a.end());

    for (long long exp = 1; mx / exp > 0; exp *= 10) {
        countByDigit(a, exp);
    }
}

int main() {
    vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(a);

    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}