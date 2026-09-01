//reverse words in string

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words (stringstream automatically skips extra spaces)
    while (ss >> word) {
        words.push_back(word);
    }

    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += " ";
    }

    return result;
}

int main() {
    string s1 = "the sky is blue";
    string s2 = "  hello   world  ";

    cout << "\"" << s1 << "\" -> \"" << reverseWords(s1) << "\"" << endl;
    cout << "\"" << s2 << "\" -> \"" << reverseWords(s2) << "\"" << endl;

    return 0;
}