// Minimum Window Substring (Sliding Window)

#include <iostream>
#include <string>
#include <climits>
using namespace std;

string minWindow(const string& s, const string& t) {
    if (t.empty()) return "";

    int need[128] = {0};
    for (char c : t) need[(unsigned char)c]++;

    int missing = t.size();
    int left = 0, bestStart = 0, bestLen = INT_MAX;

    for (int right = 0; right < (int)s.size(); right++) {
        if (need[(unsigned char)s[right]]-- > 0) missing--;   // this char was still needed

        while (missing == 0) {                                // window is valid, try shrinking
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
            if (++need[(unsigned char)s[left]] > 0) missing++;
            left++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

int main() {
    cout << "[" << minWindow("ADOBECODEBANC", "ABC") << "]" << endl;
    cout << "[" << minWindow("a", "a") << "]" << endl;
    cout << "[" << minWindow("a", "aa") << "]" << endl;
    return 0;
}