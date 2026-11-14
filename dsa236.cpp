// Next Permutation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& a) {
    int n = a.size();
    int i = n - 2;

    while (i >= 0 && a[i] >= a[i + 1]) i--;      // last position that can still grow

    if (i >= 0) {
        int j = n - 1;
        while (a[j] <= a[i]) j--;                // smallest value to the right that beats a[i]
        swap(a[i], a[j]);
    }
    reverse(a.begin() + i + 1, a.end());         // the tail is descending, make it ascending
}

void print(vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> a = {1, 2, 3}, b = {3, 2, 1}, c = {1, 1, 5};

    nextPermutation(a); print(a);
    nextPermutation(b); print(b);
    nextPermutation(c); print(c);
    return 0;
}