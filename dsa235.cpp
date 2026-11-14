// Majority Element (Boyer-Moore Voting)

#include <iostream>
#include <vector>
using namespace std;

int majority(vector<int>& a) {
    int cand = 0, count = 0;

    for (int x : a) {
        if (count == 0) cand = x;
        count += (x == cand) ? 1 : -1;
    }
    return cand;
}

int main() {
    vector<int> a = {2, 2, 1, 1, 1, 2, 2};
    vector<int> b = {3, 2, 3};

    cout << majority(a) << endl;
    cout << majority(b) << endl;
    return 0;
}