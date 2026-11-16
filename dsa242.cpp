// Generate Parentheses (Backtracking)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void gen(int open, int close, int n, string& cur, vector<string>& res) {
    if (cur.size() == 2 * n) {
        res.push_back(cur);
        return;
    }

    if (open < n) {                       // can always add an opening bracket if any are left
        cur.push_back('(');
        gen(open + 1, close, n, cur, res);
        cur.pop_back();
    }
    if (close < open) {                   // a closing bracket needs an unmatched opening one
        cur.push_back(')');
        gen(open, close + 1, n, cur, res);
        cur.pop_back();
    }
}

int main() {
    vector<string> res;
    string cur;
    gen(0, 0, 3, cur, res);

    for (auto& s : res) cout << s << endl;
    return 0;
}