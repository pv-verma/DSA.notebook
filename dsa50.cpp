#include <iostream>
using namespace std;

// painter partition problem using binary search

int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1;
    int timeSum = 0;

    for(int i = 0; i < n; i++) {
        if(timeSum + arr[i] <= mid) {
            timeSum += arr[i];
        }
        else {
            painters++;
            if(painters > k || arr[i] > mid) {
                return false;
            }
            timeSum = arr[i];
        }
        if(painters > k) {
            return false;
        }
    }
    return true;
}

int allocatePainters(int arr[], int n, int k) {
    int s = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter number of boards: ";
    cin >> n;
    int arr[n];
    cout << "Enter time required for each board: "<<endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter number of painters: ";
    cin >> k;

    cout << "Minimum time required to paint all boards is: " << allocatePainters(arr, n, k) << endl;
    return 0;
}  
