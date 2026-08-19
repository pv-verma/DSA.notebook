//Subarray Sum Equals K Using unordered_map

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> prefixCount;   // prefix sum -> how many times seen
    prefixCount[0] = 1;   // empty prefix sums to 0

    int sum = 0, count = 0;

    for (int num : arr) {
        sum += num;

        // If (sum - k) was seen before, those subarrays sum to k
        if (prefixCount.find(sum - k) != prefixCount.end()) {
            count += prefixCount[sum - k];
        }

        prefixCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 1, 1};
    int k = 2;

    cout << "Number of subarrays with sum " << k << ": " << subarraySum(arr, k) << endl;

    return 0;
}