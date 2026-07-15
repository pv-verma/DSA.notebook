#include <iostream>
#include <math.h>
using namespace std;

// binary to decimal conversion

int main () {

    int n;
    cin>> n;

    int i = 0;
    int ans = 0;

    while (n != 0) {
        int bit = n % 10;
        ans = ans + (bit * pow(2, i));
        n = n / 10;
        i++;
    }

    cout << "Answer is " << ans << endl;

    return 0;
}