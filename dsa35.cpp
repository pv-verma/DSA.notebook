#include <iostream>
using namespace std;

// finding intersection or common elements present  in two arrays sorted in non decreasing order

void findCommonElements(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0;
    cout << "Common elements are: ";
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    cout << endl;
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[6] = {4, 5, 6, 7, 8, 9};

    findCommonElements(arr1, 5, arr2, 6);

    return 0;
}