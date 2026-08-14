#include <iostream>
#include <vector>
using namespace std;

//Add array

void addArrays(const vector<int>& arr1, const vector<int>& arr2, vector<int>& result) {
    int n = arr1.size();
    int m = arr2.size();
    int maxSize = max(n, m);
    result.resize(maxSize);

    for (int i = 0; i < maxSize; i++) {
        int val1 = (i < n) ? arr1[i] : 0;
        int val2 = (i < m) ? arr2[i] : 0;
        result[i] = val1 + val2;
    }
}

int main(){
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {4, 5, 6, 7};
    vector<int> result;

    cout << "Array 1: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    addArrays(arr1, arr2, result);

    cout << "Resultant array after addition: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}