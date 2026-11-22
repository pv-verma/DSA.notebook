// Hash Map From Scratch (Separate Chaining)

#include <iostream>
#include <list>
using namespace std;

class MyMap {
    static const int B = 5;                       // tiny bucket count so collisions are easy to see
    list<pair<int, int>> table[B];

    int idx(int k) { return ((k % B) + B) % B; }  // safe for negative keys

public:
    void put(int k, int v) {
        for (auto& p : table[idx(k)]) {
            if (p.first == k) {
                p.second = v;                     // key exists, overwrite
                return;
            }
        }
        table[idx(k)].push_back({k, v});
    }

    int get(int k, int notFound = -1) {
        for (auto& p : table[idx(k)]) {
            if (p.first == k) return p.second;
        }
        return notFound;
    }

    bool remove(int k) {
        auto& l = table[idx(k)];
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (it->first == k) {
                l.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    MyMap m;
    m.put(1, 10);
    m.put(6, 60);         // 1, 6 and 11 all land in bucket 1
    m.put(11, 110);
    m.put(1, 15);         // update, not a second entry

    cout << m.get(6) << " " << m.get(1) << endl;

    cout << (m.remove(6) ? "removed" : "missing") << endl;
    cout << m.get(6) << " " << m.get(11) << endl;
    return 0;
}