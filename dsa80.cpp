//Search and Count Occurrences Using find and count

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {4, 2, 7, 2, 9, 2, 5};
    int target = 2;

    // Using find() to check existence
    auto it = find(arr.begin(), arr.end(), target);

    if (it != arr.end()) {
        cout << target << " found at index " << (it - arr.begin()) << endl;
    } else {
        cout << target << " not found" << endl;
    }

    // Using count() to count occurrences
    int occurrences = count(arr.begin(), arr.end(), target);
    cout << target << " occurs " << occurrences << " times" << endl;

    return 0;
}