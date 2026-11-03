// Activity Selection (Greedy Interval Scheduling)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> acts = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}
    };

    // sort by END time, not start time
    sort(acts.begin(), acts.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    int lastEnd = -1, count = 0;

    cout << "Picked: ";
    for (const auto& act : acts) {
        int s = act.first;
        int e = act.second;
        if (s >= lastEnd) {          // starts after the previous pick finished
            cout << "(" << s << "," << e << ") ";
            lastEnd = e;
            count++;
        }
    }
    cout << endl << "Total: " << count << endl;
    return 0;
}