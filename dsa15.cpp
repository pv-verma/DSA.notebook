#include <iostream>
using namespace std;

// bitwise operators

int main() {

    int a = 5;
    int b = 3;
    int c = a & b;  // bitwise AND
    int d = a | b;  // bitwise OR
    int e = a ^ b;  // bitwise XOR
    int f = ~ a;  // bitwise NOT

    cout << "a & b = " << c << endl;
    cout << "a | b = " << d << endl;
    cout << "a ^ b = " << e << endl;
    cout << "~ a = " << f << endl;

    // left shift nad right shift operators

    cout << (17>>1) << endl;
    cout << (17<<2) << endl;
    cout << (19<<1) << endl;
    cout << (19<<2) << endl;

    // increment and decrement operators
    int i = 7;
    cout << (i++) << endl;
    cout << (++i) << endl;
    cout << (i--) <<endl;
    cout <<( --i) <<endl;

    int x, y = 1;
    x = 10;
    if (++x)
        cout << y;
    else
        cout <<++y;

  
    return 0;
}