#include <iostream>
using namespace std;

// book alocation problem using binary search
int isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    int s = 0;
    int sum = 0;
    
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter number of books: ";
    cin >> n;
    int arr[n];
    cout << "Enter number of pages in each book: ";
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter number of students: ";
    cin >> m;

    cout << "Minimum number of pages allocated to a student is: " << allocateBooks(arr, n, m) << endl;
    return 0;
}
