// Min-Heap From Scratch

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MinHeap {
    vector<int> a;

public:
    void push(int x) {
        a.push_back(x);
        int i = a.size() - 1;

        while (i > 0) {                       // sift up
            int p = (i - 1) / 2;
            if (a[p] <= a[i]) break;
            swap(a[p], a[i]);
            i = p;
        }
    }

    int pop() {                               // caller must check empty() first
        int top = a[0];
        a[0] = a.back();
        a.pop_back();

        int i = 0, n = a.size();
        while (true) {                        // sift down
            int l = 2 * i + 1, r = 2 * i + 2, s = i;
            if (l < n && a[l] < a[s]) s = l;
            if (r < n && a[r] < a[s]) s = r;
            if (s == i) break;
            swap(a[i], a[s]);
            i = s;
        }
        return top;
    }

    bool empty() { return a.empty(); }
};

int main() {
    MinHeap h;
    int vals[] = {5, 3, 8, 1, 4};
    for (int v : vals) h.push(v);

    while (!h.empty()) cout << h.pop() << " ";
    cout << endl;
    return 0;
}