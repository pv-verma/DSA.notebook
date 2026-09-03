// max occurring character in a string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// create an array of count of characters
char getMaxOccChar(string s) {
    int arr[26] = {0};


    for (int i=0; i<s.length(); i++) {
        char ch = s[i];
        // lowercase
        if (ch>= 'a' && ch <= 'z') {
            int n = ch - 'a';
            arr[n]++;
        }
        else {  //uppercase
            int n = ch - 'A';
            arr[n]++;
        }
    }

    int maxi = -1, ans=0;
    for (int i=0; i<26; i++) {
        if (maxi < arr[i] ) {
            ans= i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Max occurring character: " << getMaxOccChar(s) << endl;

    return 0;
}