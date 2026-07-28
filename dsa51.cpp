#include <iostream>
#include <algorithm>
using namespace std;

// Aggresive cows problem using binary search

int isPossible(int arr[], int n, int k, int mid) {
    int cowCount = 1;
    int lastPos = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int aggressiveCows(int arr[], int n, int k) {
    int s = 0;
    int e = arr[n - 1] - arr[0];
    int ans = -1;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;
    int arr[n];
    cout << "Enter positions of stalls: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter number of cows: ";
    cin >> k;

    // Sort the array to ensure the positions are in order
    sort(arr, arr + n);

    cout << "Largest minimum distance between cows is: " << aggressiveCows(arr, n, k) << endl;
    return 0;
}