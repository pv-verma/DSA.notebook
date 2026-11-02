//KMP Pattern Search (Strings)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> buildLPS(const string& p) {
    int m = p.size();
    vector<int> lps(m, 0);   // lps[i] = longest proper prefix of p[0..i] that is also a suffix
    int len = 0;

    for (int i = 1; i < m;) {
        if (p[i] == p[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];      // fall back, do not advance i
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int kmpSearch(const string& text, const string& pat) {
    if (pat.empty()) return 0;

    vector<int> lps = buildLPS(pat);
    int m = pat.size();
    int j = 0;

    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pat[j]) j = lps[j - 1];
        if (text[i] == pat[j]) j++;
        if (j == m) return i - m + 1;
    }
    return -1;
}

int main() {
    cout << kmpSearch("ababcabcabababd", "ababd") << endl;
    cout << kmpSearch("hello", "ll") << endl;
    cout << kmpSearch("aaaaa", "bba") << endl;
    return 0;
}