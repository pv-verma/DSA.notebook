// Partition Labels

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> partitionLabels(const string& s) {
    int last[26];
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;   // last position of each letter

    vector<int> res;
    int start = 0, end = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        end = max(end, last[s[i] - 'a']);       // this part must stretch at least this far
        if (i == end) {                         // nothing seen so far appears later
            res.push_back(i - start + 1);
            start = i + 1;
        }
    }
    return res;
}

int main() {
    for (int x : partitionLabels("ababcbacadefegdehijhklij")) cout << x << " ";
    cout << endl;
    for (int x : partitionLabels("eccbbbbdec")) cout << x << " ";
    cout << endl;
    return 0;
}