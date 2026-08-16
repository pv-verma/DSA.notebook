// Count Vowels in a String Using count_if

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "hello world";

    int vowelCount = count_if(s.begin(), s.end(), [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    });

    cout << "Vowel count: " << vowelCount << endl;
    return 0;
}