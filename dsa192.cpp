// Course Schedule (Topological Sort with Kahn’s Algorithm)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& prereq) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (auto& p : prereq) {
        adj[p[1]].push_back(p[0]);   // edge: b -> a
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    if (order.size() != n) return {};   // some nodes never reached indegree 0
    return order;
}

void run(int n, vector<vector<int>> prereq) {
    vector<int> order = findOrder(n, prereq);
    if (order.empty()) cout << "Impossible (cycle)" << endl;
    else {
        for (int x : order) cout << x << " ";
        cout << endl;
    }
}

int main() {
    run(4, {{1,0}, {2,0}, {3,1}, {3,2}});
    run(2, {{1,0}, {0,1}});
    return 0;
}