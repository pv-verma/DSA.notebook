#include <iostream>
using namespace std;

// fibonacci seies
int main(){
    int n;
    cin >> n;
    int a = 0;
    int b= 1;

    for (int i= 1; i<=n; i++) {
        cout << a << endl;
        int next = a+ b ;
        a = b;
        b = next;
    }
    return 0;

}