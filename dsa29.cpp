#include <iostream>
using namespace std;

bool search(int arr[], int size, int key) {

    for (int i=0; i<size; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    bool found = search(arr, 5, key);

    if (found) {
        cout << "Key is present in the array" << endl;
    } else {
        cout << "Key is not present in the array" << endl;
    }

    return 0;
}