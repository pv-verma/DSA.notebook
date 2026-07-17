#include <iostream>
using namespace std;

int findDuplicate(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < n; i++) {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{

    int arr[6] = {1, 2, 3, 4, 5, 3};
    cout << "The duplicate element is: " << findDuplicate(arr, 6) << endl;

    return 0;
}