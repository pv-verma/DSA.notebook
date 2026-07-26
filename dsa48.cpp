#include <iostream>
using namespace std;

// square root using binary search (floor value)

int Sqrt(int n) {
    int s = 0, e = n;
    long long int ans = -1;     // Use long long to avoid overflow

    while (s <= e) {
        long long int mid = s + (e - s) / 2;
        long long int square = (long long int)mid * mid; 

        if (square == n) {
            return mid; // Exact square root found
        }
        else if (square < n) {
            ans = mid; // Update answer and search in the right half
            s = mid + 1;
        }
        else {
            e = mid - 1; // Search in the left half
        }
    }
    return ans; // Return the floor value of the square root
}

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++) {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int tempSol = Sqrt(n);

    cout << "Square root of " << n << " is : " << morePrecision(n, 3, tempSol) << endl;
    return 0;
}