// Kth Largest Element in a Stream

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;   // min-heap holding the k largest
    int k;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums) add(x);
    }

    int add(int v) {
        pq.push(v);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kl(3, nums);

    int stream[] = {3, 5, 10, 9, 4};
    for (int v : stream) cout << kl.add(v) << " ";
    cout << endl;
    return 0;
}