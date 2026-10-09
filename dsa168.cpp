// Jagged Array (Rows of Different Lengths)

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    int** tri = new int*[n];

    for (int i = 0; i < n; i++) {
        tri[i] = new int[i + 1];      // row i gets its own size
        tri[i][0] = 1;
        tri[i][i] = 1;

        for (int j = 1; j < i; j++) {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] tri[i];
    }
    delete[] tri;

    return 0;
}