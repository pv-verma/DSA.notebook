// checking anagram
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> freq;

    for (char c : s1) freq[c]++;
    for (char c : s2) freq[c]--;

    for (auto it : freq) {
        if (it.second != 0) return false;
    }

    return true;
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    string s3 = "hello";
    string s4 = "world";

    cout << s1 << " & " << s2 << " -> " << (isAnagram(s1, s2) ? "Anagram" : "Not Anagram") << endl;
    cout << s3 << " & " << s4 << " -> " << (isAnagram(s3, s4) ? "Anagram" : "Not Anagram") << endl;

    return 0;
}