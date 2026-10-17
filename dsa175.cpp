//Longest Palindromic Substring (Strings + Two Pointers)

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, maxLen = 1;
    int n = s.size();

    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        int len = r - l - 1;           // l and r each overshot by one
        if (len > maxLen) {
            maxLen = len;
            start = l + 1;
        }
    };

    for (int i = 0; i < n; i++) {
        expand(i, i);       // odd length, centered on a character
        expand(i, i + 1);   // even length, centered between two characters
    }

    return s.substr(start, maxLen);
}

int main() {
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("cbbd") << endl;

    return 0;
}