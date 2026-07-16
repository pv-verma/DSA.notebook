#include <iostream>
using namespace std;

void update(int arr[], int n) {

    cout << " Inside the update function"<< endl;

    for (int i=0; i<3;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Going back to the main function" << endl;
}

int main() {

    int arr[3] = {1, 2, 3};

    update(arr, 3);

    // printing the updated array
    for (int i = 0; i< 3; i++) {
        cout << arr[i] << " ";
    }

    
    return 0;
}