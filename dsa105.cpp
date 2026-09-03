// remove adjacent duplicates from string

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (ans.length() > 0 && ans.back() == s[i]) {
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }


};

int main() {
    Solution obj;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << obj.removeDuplicates(s) << endl; // Output: "ca"
    return 0;
}