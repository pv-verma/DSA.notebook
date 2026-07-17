// correct it and find solution 
#include <iostream>
using namespace std;

// finding all duplicate elements in an array where all elements except two are present once

int findallDuplicate(int arr[], int n)
{
    int ans = 0;
    for (int i=0; i<n ;i++) {
        ans = ans ^ arr[i];

    }
    for (int i=1 ; i< n; i++) {

        ans = ans ^ i;

    }
    return ans;
}

int main()
{

    int arr[7] = {1, 2, 3, 4, 5, 3, 2};
    cout << "The duplicate elements are: " << findallDuplicate(arr, 7) << endl;

    return 0;
}