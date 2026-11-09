// Shortest Tour Visiting All Cities (Bitmask DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int tsp(vector<vector<int>>& d) {
    int n = d.size();
    int full = 1 << n;

    // dp[mask][i] = shortest way to visit exactly the cities in mask, ending at city i
    vector<vector<int>> dp(full, vector<int>(n, INF));
    dp[1][0] = 0;                                   // only city 0 visited, standing at 0

    for (int mask = 1; mask < full; mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == INF || !(mask & (1 << i))) continue;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;      // already visited
                int next = mask | (1 << j);
                dp[next][j] = min(dp[next][j], dp[mask][i] + d[i][j]);
            }
        }
    }

    int best = INF;
    for (int i = 1; i < n; i++) {
        if (dp[full - 1][i] != INF) best = min(best, dp[full - 1][i] + d[i][0]);
    }
    return best;
}

int main() {
    vector<vector<int>> d = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Shortest tour: " << tsp(d) << endl;
    return 0;
}