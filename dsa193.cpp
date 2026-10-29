// Dijkstra’s Shortest Path (Weighted Graph)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;   // {distance, node}

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int d = current.first;
        int u = current.second;
        pq.pop();

        if (d > dist[u]) continue;   // stale entry, a shorter route was already found

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    vector<int> dist = dijkstra(n, adj, 0);

    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << ": ";
        if (dist[i] == INT_MAX) cout << "unreachable" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}