//Find the First Repeating Character in a String

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

char firstRepeatingChar(string s) {
    unordered_set<char> seen;

    for (char c : s) {
        if (seen.find(c) != seen.end()) {
            return c;   // first char we encounter a second time
        }
        seen.insert(c);
    }

    return '\0';   // no repeating character found
}

int main() {
    string s1 = "swiss";
    string s2 = "abcdef";
    string s3 = "programming";

    char r1 = firstRepeatingChar(s1);
    char r2 = firstRepeatingChar(s2);
    char r3 = firstRepeatingChar(s3);

    cout << s1 << " -> " << (r1 != '\0' ? string(1, r1) : "None") << endl;
    cout << s2 << " -> " << (r2 != '\0' ? string(1, r2) : "None") << endl;
    cout << s3 << " -> " << (r3 != '\0' ? string(1, r3) : "None") << endl;

    return 0;
}