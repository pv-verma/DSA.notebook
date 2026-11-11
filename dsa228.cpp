// Median From a Data Stream (Two Heaps)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> lo;                                  // max-heap, smaller half
    priority_queue<int, vector<int>, greater<int>> hi;       // min-heap, larger half

public:
    void addNum(int x) {
        lo.push(x);
        hi.push(lo.top());          // push through lo so every value in lo <= every value in hi
        lo.pop();

        if (hi.size() > lo.size()) {   // keep lo equal in size or one larger
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

int main() {
    MedianFinder m;
    int stream[] = {1, 2, 3, 10};

    for (int x : stream) {
        m.addNum(x);
        cout << m.findMedian() << " ";
    }
    cout << endl;
    return 0;
}