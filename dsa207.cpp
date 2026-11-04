// Floyd-Warshall (All-Pairs Shortest Path)

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n = 4;
    vector<vector<int>> d(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) d[i][i] = 0;
    d[0][1] = 5;
    d[0][3] = 10;
    d[1][2] = 3;
    d[2][3] = 1;

    for (int k = 0; k < n; k++) {              // k MUST be the outermost loop
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF) cout << "INF ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}