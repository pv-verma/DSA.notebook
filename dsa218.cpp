// Word Search on a Grid (Backtracking)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<string>& g, const string& w, int r, int c, int k) {
    if (k == w.size()) return true;
    if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] != w[k]) {
        return false;
    }

    char saved = g[r][c];
    g[r][c] = '#';                      // mark as used on this path

    bool found = dfs(g, w, r + 1, c, k + 1) ||
                 dfs(g, w, r - 1, c, k + 1) ||
                 dfs(g, w, r, c + 1, k + 1) ||
                 dfs(g, w, r, c - 1, k + 1);

    g[r][c] = saved;                    // undo, other paths may need this cell
    return found;
}

bool exist(vector<string> g, const string& w) {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            if (dfs(g, w, i, j, 0)) return true;
        }
    }
    return false;
}

int main() {
    vector<string> g = {"ABCE", "SFCS", "ADEE"};

    cout << (exist(g, "ABCCED") ? "Yes" : "No") << endl;
    cout << (exist(g, "SEE") ? "Yes" : "No") << endl;
    cout << (exist(g, "ABCB") ? "Yes" : "No") << endl;
    return 0;
}