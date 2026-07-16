#include <iostream>
using namespace std;

int main() {

    int amount = 1330;

    switch (amount) {

        case 1330: 
            cout << "100 rupee notes are "<< amount % 100 << endl;
            int amountleft = amount - ((amount / 100) * 100);
        case 30:
            cout << "20 rupee notes are "<< amountleft % 20 << endl;
            int amountleft = amountleft - ((amountleft / 20) * 20);
        case 10:
            cout << "10 rupee notes are "<< amountleft % 10 << endl;
            int amountleft = amountleft - ((amountleft / 10) * 10);
    }
    return 0;
}