// string compression

#include <iostream>
#include <vector>
using namespace std;
class Solution{

public:
    int compressString(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;

        int n = chars.size();
        while(i<n) {
            int j = i+1;
            while(j<n && chars[i] == chars[j]) {
                j++;
            }
            // when to come here
            // if vector is completely tranversed
            //or new/ different character is found
            chars[ansIndex++] = chars[i];

            int count = j-i;
            if(count>1) {
                // converting counting into single digit and saving
                string cnt = to_string(count);
                for(char ch: cnt) {
                    chars[ansIndex++] = ch;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};

int main() {
    Solution obj;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int newLength = obj.compressString(chars);
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for(int i=0; i<newLength; i++) {
        cout << chars[i];
    }
    cout << endl;
    return 0;
}