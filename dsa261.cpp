// Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void gen(const string& digits, int i, string& cur, vector<string>& res) {
    if (i == (int)digits.size()) {
        res.push_back(cur);
        return;
    }

    for (char c : keys[digits[i] - '0']) {
        cur.push_back(c);
        gen(digits, i + 1, cur, res);
        cur.pop_back();
    }
}

vector<string> letterCombinations(const string& digits) {
    vector<string> res;
    if (digits.empty()) return res;          // no digits means no combinations, not one empty string

    string cur;
    gen(digits, 0, cur, res);
    return res;
}

int main() {
    for (auto& s : letterCombinations("23")) cout << s << " ";
    cout << endl;

    for (auto& s : letterCombinations("7")) cout << s << " ";
    cout << endl;
    return 0;
}