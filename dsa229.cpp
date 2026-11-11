// Decode Ways (String DP)

#include <iostream>
#include <string>
using namespace std;

int numDecodings(const string& s) {
    if (s.empty() || s[0] == '0') return 0;

    int n = s.size();
    int prev2 = 1;   // ways for the prefix two characters back
    int prev1 = 1;   // ways for the prefix one character back

    for (int i = 2; i <= n; i++) {
        int cur = 0;

        if (s[i - 1] != '0') cur += prev1;               // last digit alone: 1 to 9

        int two = stoi(s.substr(i - 2, 2));
        if (two >= 10 && two <= 26) cur += prev2;         // last two digits together

        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << numDecodings("12") << endl;
    cout << numDecodings("226") << endl;
    cout << numDecodings("06") << endl;
    return 0;
}