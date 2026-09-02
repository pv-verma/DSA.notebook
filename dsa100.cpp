// reverse words in a string

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.length() - 1;
        
        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            
            if(i < 0) break;
            
            int j = i;
            while(j >= 0 && s[j] != ' ') {
                j--;
            }
            
            if(ans.length() > 0) {
                ans += " ";
            }
            
            ans += s.substr(j + 1, i - j);
            i = j;
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    string output = solution.reverseWords(input);
    cout << "Reversed words: \"" << output << "\"" << endl;
    return 0;
}