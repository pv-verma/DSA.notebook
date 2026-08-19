//Top K Frequent Elements Using unordered_map + priority_queue

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;

    // min-heap of (frequency, value), keep only top k
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    for (const auto& entry : freq) {
        int val = entry.first;
        int count = entry.second;
        minHeap.push({count, val});
        if (minHeap.size() > k) {
            minHeap.pop();   // remove least frequent
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;   // note: order here is least-to-most frequent among top k
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    int k = 2;

    vector<int> result = topKFrequent(arr, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}