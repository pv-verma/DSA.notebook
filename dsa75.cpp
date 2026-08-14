#include <iostream>
#include <vector>
using namespace std;

//rotate array

void rotateArray(vector<int>& arr, int k) {
    
    vector<int> temp(arr.size());
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    arr = temp;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rotateArray(arr, k);

    cout << "Rotated array by " << k << " positions: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
