//Find the Minimum Occurring Character in a String

#include <iostream>
#include <string>
#include <climits>
using namespace std;

char getMinOccChar(string s) {
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch >= 'a' && ch <= 'z') {
            arr[ch - 'a']++;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            arr[ch - 'A']++;
        }
    }

    int mini = INT_MAX, ans = 0;

    for (int i = 0; i < 26; i++) {
        // Only consider characters that actually appeared (count > 0)
        if (arr[i] > 0 && arr[i] < mini) {
            mini = arr[i];
            ans = i;
        }
    }

    return 'a' + ans;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Min occurring character: " << getMinOccChar(s) << endl;

    return 0;
}