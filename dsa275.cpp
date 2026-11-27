// Huffman Coding Cost (Greedy + Heap)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long huffmanCost(const vector<int>& freq) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int f : freq) pq.push(f);

    long long total = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();        // two rarest symbols go deepest
        long long b = pq.top(); pq.pop();
        total += a + b;                          // merging adds one bit to everything below
        pq.push(a + b);
    }
    return total;
}

int main() {
    cout << huffmanCost({5, 9, 12, 13, 16, 45}) << endl;
    cout << huffmanCost({1, 1}) << endl;
    cout << huffmanCost({7}) << endl;
    return 0;
}