#include <iostream>
#include <vector>
using namespace std;

//insertion sort 

void insertionSort(int arr[], int n) {

    for ( int i = 1; i<n; i++) {
        int temp = arr[i];

        int j = i-1;
        for(; j>=0;j--) {

            if (arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { //stop here
                break;
            }
        }
        arr[j+1] = temp;
    }

}


int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr,n);
    
    cout << "Sorted array : \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


   
    return 0;
}
