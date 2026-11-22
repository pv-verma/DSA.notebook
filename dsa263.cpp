// Meeting Rooms II

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minRooms(vector<pair<int, int>> m) {
    sort(m.begin(), m.end());                                    // by start time
    priority_queue<int, vector<int>, greater<int>> ends;          // end times of rooms in use

    for (auto it = m.begin(); it != m.end(); ++it) {
        int s = it->first, e = it->second;
        if (!ends.empty() && ends.top() <= s) ends.pop();         // earliest room is free, reuse it
        ends.push(e);
    }
    return ends.size();
}

int main() {
    cout << minRooms({{0, 30}, {5, 10}, {15, 20}}) << endl;
    cout << minRooms({{7, 10}, {2, 4}}) << endl;
    cout << minRooms({{1, 5}, {5, 9}}) << endl;
    return 0;
}