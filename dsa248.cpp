// Equilibrium Index

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int equilibrium(const vector<int>& a) {
    long long total = 0;
    for (int value : a) {
        total += value;
    }

    long long left = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        long long right = total - left - a[i];
        if (left == right) return i;
        left += a[i];
    }
    return -1;
}

int main() {
    vector<int> a = {1, 3, 5, 2, 2};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1};

    cout << equilibrium(a) << endl;
    cout << equilibrium(b) << endl;
    cout << equilibrium(c) << endl;
    return 0;
}