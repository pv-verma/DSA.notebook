// Josephus Problem

#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int res = 0;                         // survivor index when 1 person remains (0-based)
    for (int i = 2; i <= n; i++) {
        res = (res + k) % i;             // map the answer back to a circle of size i
    }
    return res + 1;                      // convert to 1-based
}

int main() {
    cout << josephus(7, 3) << endl;
    cout << josephus(5, 2) << endl;
    cout << josephus(1, 5) << endl;
    return 0;
}