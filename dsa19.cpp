#include <iostream>
#include <math.h>
using namespace std;

// not solved correctly 

// decimal to binary conversion


int main() {

    int n;
    cin>> n;

    int i = 0;
    int ans = 0;
   

    while(n != 0) {
        

        int bit = n & 1;
        ans = ( bit * pow(10, i)) + ans;

        n = n>>1;
        i++;

    }     
    cout << "Answer is " << ans << endl;

    return 0;
}