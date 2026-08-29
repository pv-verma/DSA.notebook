// reverse string 

#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void reverseString(vector<char>& s) {
        int st=0;
        int e = s.size()-1;

        while(st<e) {
            swap(s[st++], s[e--]);
        }
    }
};

int main() {
    Solution sol;

    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s1);
    cout << "Reversed: ";
    for (char c : s1) cout << c;
    cout << endl;

    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    sol.reverseString(s2);
    cout << "Reversed: ";
    for (char c : s2) cout << c;
    cout << endl;

    return 0;
}