#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;
    if (ch >= 'a' && ch <= 'z') {
        cout << "Lowercase letter" << endl;
    } else if (ch >= 'A' && ch <= 'Z') {
        cout << "Uppercase letter" << endl;
    } else if (ch >= '0' && ch <= '9') {
        cout << "Numeric" << endl;
    } else {
        cout << "Special character" << endl;
    }
    return 0;
}