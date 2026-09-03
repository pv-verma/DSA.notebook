// replace spaces with preffered string (inplace)

#include <iostream>
#include <string>
using namespace std;

void replaceSpaces(string &s, string &replacement) {
    // Find the first space
    size_t pos = s.find(' ');
    if (pos == string::npos) {
        return; // No spaces to replace
    }

    // Replace the first space with the replacement string
    s.replace(pos, 1, replacement);

    // Recursively call the function to replace any remaining spaces
    replaceSpaces(s, replacement);
}

int main() {
    string s;
    getline(cin, s);
    string replacement = "@40";
    replaceSpaces(s, replacement);
    cout << s << endl;
    return 0;
}