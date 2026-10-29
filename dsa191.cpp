// Shortest Path in an Unweighted Graph (BFS)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dest) break;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;       // remember how we reached v
                q.push(v);
            }
        }
    }

    if (!visited[dest]) return {};   // unreachable

    vector<int> path;
    for (int x = dest; x != -1; x = parent[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    int edges[][2] = {{0,1}, {0,2}, {1,3}, {2,3}, {3,4}, {4,5}};

    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> path = shortestPath(n, adj, 0, 5);

    if (path.empty()) cout << "No path" << endl;
    else {
        cout << "Length: " << path.size() - 1 << endl;
        cout << "Path: ";
        for (int x : path) cout << x << " ";
        cout << endl;
    }
    return 0;
}