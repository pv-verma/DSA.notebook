// Remove Adjacent Duplicates in a String

#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    string res;   // used as a stack

    for (char c : s) {
        if (!res.empty() && res.back() == c) {
            res.pop_back();
        } else {
            res.push_back(c);
        }
    }
    return res;
}

int main() {
    cout << removeDuplicates("abbaca") << endl;
    cout << removeDuplicates("azxxzy") << endl;

    return 0;
}