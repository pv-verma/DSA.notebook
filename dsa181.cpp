// Maximum Subarray Sum with Indices (Kadane’s Algorithm)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int cur = arr[0], best = arr[0];
    int tempStart = 0, start = 0, end = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (cur < 0) {
            cur = arr[i];                 // a negative running sum only hurts, so restart
            tempStart = i;
        } else {
            cur += arr[i];
        }

        if (cur > best) {
            best = cur;
            start = tempStart;
            end = i;
        }
    }

    cout << "Max sum: " << best << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}