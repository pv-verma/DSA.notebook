// Bellman-Ford With Negative Cycle Detection

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

const long long INF = 1e18;

bool bellmanFord(int n, vector<Edge>& edges, int src, vector<long long>& dist) {
    dist.assign(n, INF);
    dist[src] = 0;

    for (int pass = 1; pass <= n - 1; pass++) {
        bool changed = false;
        for (auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;               // already stable, stop early
    }

    for (auto& e : edges) {                // one extra pass: any improvement means a negative cycle
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) return false;
    }
    return true;
}

int main() {
    vector<long long> dist;

    vector<Edge> g1 = {
        {0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5}, {1, 4, -4},
        {2, 3, -3}, {2, 4, 9}, {3, 1, -2}, {4, 3, 7}, {4, 0, 2}
    };

    if (bellmanFord(5, g1, 0, dist)) {
        for (int i = 0; i < 5; i++) cout << "dist[" << i << "] = " << dist[i] << endl;
    }

    vector<Edge> g2 = {{0, 1, 1}, {1, 2, -1}, {2, 1, -1}};
    cout << (bellmanFord(3, g2, 0, dist) ? "No negative cycle" : "Negative cycle found") << endl;
    return 0;
}