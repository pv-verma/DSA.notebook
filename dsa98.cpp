// Longest Common Prefix Among an Array of Strings

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        // Shrink prefix until it matches the start of strs[i]
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }

    return prefix;
}

int main() {
    vector<string> words1 = {"flower", "flow", "flight"};
    vector<string> words2 = {"dog", "racecar", "car"};

    cout << "Common prefix: \"" << longestCommonPrefix(words1) << "\"" << endl;
    cout << "Common prefix: \"" << longestCommonPrefix(words2) << "\"" << endl;

    return 0;
}