// Word Ladder (BFS on Strings)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ladder(string begin, const string& end, vector<string>& list) {
    unordered_set<string> dict(list.begin(), list.end());
    if (!dict.count(end)) return 0;

    queue<pair<string, int>> q;
    q.push({begin, 1});

    while (!q.empty()) {

        pair<string, int> front = q.front();
        string w = front.first;
        int steps = front.second;
        q.pop();
        if (w == end) return steps;

        for (int i = 0; i < (int)w.size(); i++) {
            char orig = w[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == orig) continue;
                w[i] = c;
                if (dict.count(w)) {
                    dict.erase(w);                 // erasing doubles as the visited mark
                    q.push({w, steps + 1});
                }
            }
            w[i] = orig;
        }
    }
    return 0;
}

int main() {
    vector<string> a = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> b = {"hot", "dot", "dog", "lot", "log"};

    cout << ladder("hit", "cog", a) << endl;
    cout << ladder("hit", "cog", b) << endl;
    return 0;
}