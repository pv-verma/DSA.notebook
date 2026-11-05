// Word Break (DP on Strings)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(const string& s, const vector<string>& dict) {
    unordered_set<string> words(dict.begin(), dict.end());
    int n = s.size();

    vector<bool> dp(n + 1, false);   // dp[i] = first i characters can be split
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && words.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    cout << (wordBreak("leetcode", {"leet", "code"}) ? "Yes" : "No") << endl;
    cout << (wordBreak("applepenapple", {"apple", "pen"}) ? "Yes" : "No") << endl;
    cout << (wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) ? "Yes" : "No") << endl;
    return 0;
}