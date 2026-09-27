//  modular exponent

#include <iostream>
using namespace std;

int modularExpo(int x, int n, int m) {

    int res=1;

    while(n>0) {
        if (n&1) {
            //odd
            res =(1LL * (res) * (x)%m)%m;
        }
        x = ((x)%m * (x)%m)%m;
        n = n>>1;

    }
    return res;
}

int main() {

    int x= 3;
    int n = 4;
    int m =7 ;

    cout << modularExpo(x,n,m) ;
}