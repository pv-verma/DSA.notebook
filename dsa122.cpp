// Flood Fill Algorithm

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int row, int col, int rows, int cols, int oldColor, int newColor) {
    // Base case: out of bounds, or not the color we're filling, or already filled
    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != oldColor) {
        return;
    }

    image[row][col] = newColor;

    dfs(image, row + 1, col, rows, cols, oldColor, newColor);
    dfs(image, row - 1, col, rows, cols, oldColor, newColor);
    dfs(image, row, col + 1, rows, cols, oldColor, newColor);
    dfs(image, row, col - 1, rows, cols, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];

    // Avoid infinite recursion if new color is same as old color
    if (oldColor == newColor) return image;

    int rows = image.size();
    int cols = image[0].size();

    dfs(image, sr, sc, rows, cols, oldColor, newColor);

    return image;
}

void printImage(vector<vector<int>>& image) {
    for (auto& row : image) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    cout << "Original image:\n";
    printImage(image);

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "After flood fill:\n";
    printImage(result);

    return 0;
}