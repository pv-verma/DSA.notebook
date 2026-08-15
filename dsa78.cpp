//Find Kth Largest Element Using priority_queue (Min-Heap)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // min-heap of size k
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();   // remove smallest, keep k largest so far
        }
    }

    return minHeap.top();   // top of min-heap = kth largest
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << k << "th largest element: " << findKthLargest(nums, k) << endl;

    return 0;
}