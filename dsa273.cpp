// Gray Code

#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res;
    for (int i = 0; i < (1 << n); i++) {
        res.push_back(i ^ (i >> 1));
    }
    return res;
}

int main() {
    for (int n = 2; n <= 3; n++) {
        for (int x : grayCode(n)) cout << x << " ";
        cout << endl;
    }
    return 0;
}