//Check if Two Strings are Rotations of Each Other

#include <iostream>
#include <string>
using namespace std;

bool areRotations(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    // Trick: if s2 is a rotation of s1, then s2 must be a substring of (s1 + s1)
    string combined = s1 + s1;

    return combined.find(s2) != string::npos;
}

int main() {
    string s1, s2;
    cout << "enter first string: "<<endl;
    cin >> s1;
    cout << "enter second string: "<<endl;
    cin>> s2;

    cout << s1 << " & " << s2 << " -> " << (areRotations(s1, s2) ? "Rotation" : "Not Rotation") << endl;
    return 0;
}