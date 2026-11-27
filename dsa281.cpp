// Longest Increasing Path in a Matrix

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& g, vector<vector<int>>& memo, int i, int j) {
    if (memo[i][j]) return memo[i][j];

    int m = g.size(), n = g[0].size();
    int best = 1;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni >= 0 && nj >= 0 && ni < m && nj < n && g[ni][nj] > g[i][j]) {
            best = max(best, 1 + dfs(g, memo, ni, nj));
        }
    }
    return memo[i][j] = best;
}

int longestIncreasingPath(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int best = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            best = max(best, dfs(g, memo, i, j));
    return best;
}

int main() {
    vector<vector<int>> a = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    vector<vector<int>> b = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

    cout << longestIncreasingPath(a) << endl;
    cout << longestIncreasingPath(b) << endl;
    return 0;
}