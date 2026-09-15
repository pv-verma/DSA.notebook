// Rotten Oranges (Multi-Source BFS - Minimum Time to Rot All Oranges)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;   // stores {row, col} of rotten oranges
    int freshCount = 0;

    // Step 1: find all initially rotten oranges and count fresh ones
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) return 0;   // no fresh oranges to begin with

    int minutes = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Step 2: multi-source BFS, rotting oranges minute by minute
    while (!q.empty()) {
        int size = q.size();
        bool rottedThisMinute = false;

        for (int k = 0; k < size; k++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int newRow = row + dx[d];
                int newCol = col + dy[d];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols
                    && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    freshCount--;
                    q.push({newRow, newCol});
                    rottedThisMinute = true;
                }
            }
        }

        if (rottedThisMinute) minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);

    cout << "Minimum time to rot all oranges: " << result << " minutes" << endl;

    return 0;
}