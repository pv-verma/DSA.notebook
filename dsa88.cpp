//Kth Smallest Element in a Sorted Matrix Using priority_queue


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    // max-heap of size k: keeps the k smallest elements seen so far
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxHeap.push(matrix[i][j]);
            if (maxHeap.size() > k) {
                maxHeap.pop();   // remove largest, keep only k smallest
            }
        }
    }

    return maxHeap.top();   // top of max-heap = kth smallest overall
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    cout << k << "th smallest element: " << kthSmallest(matrix, k) << endl;

    return 0;
}