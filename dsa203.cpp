// Longest Repeating Character Replacement (Sliding Window on Strings)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int characterReplacement(const string& s, int k) {
    int freq[26] = {0};
    int left = 0, maxFreq = 0, best = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // window size minus the most common letter = replacements needed
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << characterReplacement("AABABBA", 1) << endl;
    cout << characterReplacement("ABAB", 2) << endl;
    return 0;
}