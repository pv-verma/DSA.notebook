// Rat in a Maze (All Paths, Backtracking)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<vector<int>>& g, int r, int c, string& path, vector<string>& res) {
    int n = g.size();
    if (r == n - 1 && c == n - 1) {
        res.push_back(path);
        return;
    }

    const int dr[] = {1, 0, 0, -1};
    const int dc[] = {0, -1, 1, 0};
    const char ch[] = {'D', 'L', 'R', 'U'};

    g[r][c] = 2;                                  // mark as on the current path
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nc >= 0 && nr < n && nc < n && g[nr][nc] == 1) {
            path.push_back(ch[d]);
            solve(g, nr, nc, path, res);
            path.pop_back();
        }
    }
    g[r][c] = 1;                                  // undo so other paths can use this cell
}

vector<string> findPaths(vector<vector<int>> g) {
    vector<string> res;
    int n = g.size();
    if (g[0][0] == 0 || g[n - 1][n - 1] == 0) return res;

    string path;
    solve(g, 0, 0, path, res);
    return res;
}

int main() {
    vector<vector<int>> a = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> b = {{1, 0}, {0, 1}};

    for (auto& p : findPaths(a)) cout << p << endl;

    if (findPaths(b).empty()) cout << "No path" << endl;
    return 0;
}