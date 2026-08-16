//Two Sum Using unordered_map

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    unordered_map<int, int> seen;   // value -> index

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];

        if (seen.find(complement) != seen.end()) {
            cout << "Pair found: (" << complement << ", " << arr[i] << ") "
                 << "at indices (" << seen[complement] << ", " << i << ")" << endl;
            return 0;
        }
        seen[arr[i]] = i;
    }

    cout << "No pair found" << endl;
    return 0;
}