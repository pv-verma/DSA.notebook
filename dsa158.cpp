//  C-Style Strings and Pointer Arithmetic

#include <iostream>
using namespace std;

int myStrlen(const char* str) {
    const char* ptr = str;

    while (*ptr != '\0') {   // keep moving until we hit the null terminator
        ptr++;
    }

    return ptr - str;   // pointer subtraction gives the length
}

void myStrcpy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;   // copy character
        dest++;
        src++;
    }
    *dest = '\0';   // don't forget to null-terminate the destination!
}

int main() {
    const char* s = "Hello, World!";

    cout << "Length of \"" << s << "\": " << myStrlen(s) << endl;

    char buffer[50];
    myStrcpy(buffer, s);
    cout << "Copied string: " << buffer << endl;

    return 0;
}