// Pass Array to Function and Modify It (Pointer Decay)

#include <iostream>
using namespace std;

void doubleElements(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *= 2;   // modifies the ORIGINAL array, not a copy
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Before: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    doubleElements(nums, n);   // nums decays to int* automatically

    cout << "After: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}