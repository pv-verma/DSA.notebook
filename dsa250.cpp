// Reverse a Number and Check Palindrome Number

#include <iostream>
using namespace std;

long long reverseNum(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;     // take the last digit, append it to rev
        n /= 10;
    }
    return rev;
}

bool isPalindrome(long long n) {
    if (n < 0) return false;         // the minus sign breaks symmetry
    return n == reverseNum(n);
}

int main() {
    cout << reverseNum(12345) << endl;
    cout << (isPalindrome(121) ? "Yes" : "No") << endl;
    cout << (isPalindrome(123) ? "Yes" : "No") << endl;
    cout << (isPalindrome(-121) ? "Yes" : "No") << endl;
    return 0;
}