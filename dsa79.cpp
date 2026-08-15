#include <iostream>
#include <vector>
#include <set>
using namespace std;

// removing duplicate from a vector using set

int main() {
    vector<int> arr = {5, 3, 8, 3, 5, 1, 8, 2};

    set<int> s(arr.begin(), arr.end());   // duplicates removed, auto-sorted

    cout << "Unique elements: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}