#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()!=0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    cout << sol.removeOccurrences(s1, part1) << endl;   // expected: "dab"

    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    cout << sol.removeOccurrences(s2, part2) << endl;   // expected: "ab"

    return 0;
}