// Armstrong Number

#include <iostream>
using namespace std;

long long power(int base, int exp) {
    long long r = 1;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}

bool isArmstrong(int n) {
    int digits = 0;
    for (int t = n; t > 0; t /= 10) digits++;

    long long sum = 0;
    for (int t = n; t > 0; t /= 10) sum += power(t % 10, digits);

    return sum == n;
}

int main() {
    int tests[] = {153, 9474, 123};

    for (int x : tests) {
        cout << x << ": " << (isArmstrong(x) ? "Armstrong" : "Not Armstrong") << endl;
    }
    return 0;
}