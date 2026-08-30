// longest substring without repeating characters

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;   // char -> most recent index seen
    int maxLen = 0;
    int windowStart = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If char seen before AND it's inside current window, shrink window
        if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= windowStart) {
            windowStart = lastIndex[c] + 1;
        }

        lastIndex[c] = i;
        maxLen = max(maxLen, i - windowStart + 1);
    }

    return maxLen;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << "\"" << s1 << "\" -> " << lengthOfLongestSubstring(s1) << endl;
    cout << "\"" << s2 << "\" -> " << lengthOfLongestSubstring(s2) << endl;
    cout << "\"" << s3 << "\" -> " << lengthOfLongestSubstring(s3) << endl;

    return 0;
}