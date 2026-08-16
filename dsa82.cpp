//First Non-Repeating Character Using unordered_map

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char firstNonRepeating(string s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    for (char c : s) {
        if (freq[c] == 1) {
            return c;
        }
    }

    return '\0';   // no non-repeating character found
}

int main() {
    string s = "swiss";

    char result = firstNonRepeating(s);

    if (result != '\0')
        cout << "First non-repeating character: " << result << endl;
    else
        cout << "No non-repeating character found" << endl;

    return 0;
}