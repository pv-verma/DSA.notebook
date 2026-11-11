// Fast Modular Exponentiation (Bit Tricks)

#include <iostream>
using namespace std;

long long power(long long base, long long exp, long long m) {
    long long result = 1;
    base %= m;

    while (exp > 0) {
        if (exp & 1) result = result * base % m;   // this bit of exp is set
        base = base * base % m;                    // square for the next bit
        exp >>= 1;
    }
    return result;
}

int main() {
    cout << power(2, 10, 1000) << endl;
    cout << power(3, 200, 13) << endl;
    cout << power(2, 30, 1000000007) << endl;
    return 0;
}