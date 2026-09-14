// Count Islands in a Binary Grid (Number of Islands)

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols) {
    // Base case: out of bounds or water or already visited
    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0) {
        return;
    }

    grid[row][col] = 0;   // mark as visited by sinking it

    // Explore all 4 directions
    dfs(grid, row + 1, col, rows, cols);
    dfs(grid, row - 1, col, rows, cols);
    dfs(grid, row, col + 1, rows, cols);
    dfs(grid, row, col - 1, rows, cols);
}

int numIslands(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                count++;              // found a new island
                dfs(grid, i, j, rows, cols);   // sink the whole island
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    int result = numIslands(grid);

    cout << "Number of islands: " << result << endl;

    return 0;
}