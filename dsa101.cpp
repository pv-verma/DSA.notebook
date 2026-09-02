// reverse each letter and word in a string

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
            
            // Reverse the word and add to ans
            for(int k = i; k > j; k--) {
                ans += s[k];
            }
            
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
    cout << "Reversed words and letters: \"" << output << "\"" << endl;
    return 0;
}