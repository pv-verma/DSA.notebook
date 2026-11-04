// Rotate an Array (Reversal Trick)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateRight(vector<int>& a, int k) {
    int n = a.size();
    if (n == 0) return;
    k %= n;                                   // k can exceed n

    reverse(a.begin(), a.end());              // reverse everything
    reverse(a.begin(), a.begin() + k);        // reverse the first k
    reverse(a.begin() + k, a.end());          // reverse the rest
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    rotateRight(a, 3);

    for (int x : a) cout << x << " ";
    cout << endl;

    vector<int> b = {1, 2, 3};
    rotateRight(b, 5);                        // same as rotating by 2

    for (int x : b) cout << x << " ";
    cout << endl;
    return 0;
}