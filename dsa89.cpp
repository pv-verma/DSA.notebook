//Longest Consecutive Sequence Using unordered_set

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    unordered_set<int> numSet(arr.begin(), arr.end());
    int longest = 0;

    for (int num : numSet) {
        // Only start counting if 'num' is the start of a sequence
        // (i.e., num - 1 is NOT in the set)
        if (numSet.find(num - 1) == numSet.end()) {
            int length = 1;
            int current = num;

            while (numSet.find(current + 1) != numSet.end()) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << "Longest consecutive sequence length: " << longestConsecutive(arr) << endl;
    // The sequence is 1, 2, 3, 4

    return 0;
}