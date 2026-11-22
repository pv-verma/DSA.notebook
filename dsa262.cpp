// Minimum Spanning Tree With Prim's Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

int prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inTree(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // {edge weight, node}

    pq.push({0, 0});
    int total = 0, count = 0;

    while (!pq.empty() && count < n) {
        pair<int, int> top = pq.top();
        pq.pop();
        int w = top.first;
        int u = top.second;

        if (inTree[u]) continue;
        inTree[u] = true;
        total += w;
        count++;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;
            if (!inTree[v]) pq.push({wt, v});
        }
    }
    return count == n ? total : -1;
}

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int main() {
    vector<vector<pair<int, int>>> g(5);
    addEdge(g, 0, 1, 2);
    addEdge(g, 0, 3, 6);
    addEdge(g, 1, 2, 3);
    addEdge(g, 1, 3, 8);
    addEdge(g, 1, 4, 5);
    addEdge(g, 2, 4, 7);
    addEdge(g, 3, 4, 9);

    vector<vector<pair<int, int>>> h(4);
    addEdge(h, 0, 1, 1);

    cout << prim(5, g) << endl;
    cout << prim(4, h) << endl;
    return 0;
}