// Quick Sort (Lomuto Partition)

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int partitionArr(vector<int>& a, int lo, int hi) {
    int pivot = a[hi];
    int i = lo - 1;                      // end of the "smaller than pivot" zone

    for (int j = lo; j < hi; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[hi]);               // drop the pivot into its final spot
    return i + 1;
}

void quickSort(vector<int>& a, int lo, int hi) {
    if (lo < hi) {
        int p = partitionArr(a, lo, hi);
        quickSort(a, lo, p - 1);
        quickSort(a, p + 1, hi);
    }
}

int main() {
    vector<int> a = {10, 7, 8, 9, 1, 5};
    quickSort(a, 0, a.size() - 1);

    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}