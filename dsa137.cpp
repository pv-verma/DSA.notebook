// Function Pointers ( Choosing an Operation at Runtime)

#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    // Declare a function pointer matching the signature: int func(int, int)
    int (*operation)(int, int);

    int x = 10, y = 4;
    char choice;

    cout << "Choose operation (+, -, *): ";
    cin >> choice;

    if (choice == '+') operation = add;
    else if (choice == '-') operation = subtract;
    else if (choice == '*') operation = multiply;
    else {
        cout << "Invalid choice" << endl;
        return 1;
    }

    int result = operation(x, y);   // calls whichever function was assigned
    cout << "Result: " << result << endl;

    return 0;
}