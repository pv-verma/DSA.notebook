// Factorial of a Large Number

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string bigFactorial(int n) {
    vector<int> d = {1};                    // digits, least significant first

    for (int f = 2; f <= n; f++) {
        int carry = 0;
        for (size_t i = 0; i < d.size(); i++) {
            int cur = d[i] * f + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
        while (carry) {
            d.push_back(carry % 10);
            carry /= 10;
        }
    }

    string s;
    for (int i = (int)d.size() - 1; i >= 0; i--) s.push_back('0' + d[i]);
    return s;
}

int main() {
    cout << bigFactorial(20) << endl;
    cout << bigFactorial(25) << endl;
    return 0;
}