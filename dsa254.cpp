// Game of Life (In Place)

#include <iostream>
#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& b) {
    int m = b.size(), n = b[0].size();

    // encoding: 0 dead->dead, 1 live->live, 2 live->dead, 3 dead->live
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int ni = i + dx, nj = j + dy;
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                    if (b[ni][nj] == 1 || b[ni][nj] == 2) live++;   // was alive before this step
                }
            }
            if (b[i][j] == 1 && (live < 2 || live > 3)) b[i][j] = 2;
            else if (b[i][j] == 0 && live == 3) b[i][j] = 3;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            b[i][j] %= 2;                                           // 2 -> 0, 3 -> 1
}

int main() {
    vector<vector<int>> b = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    gameOfLife(b);

    for (auto& row : b) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}