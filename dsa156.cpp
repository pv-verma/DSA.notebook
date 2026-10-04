//  The this Pointer in Classes

#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    // Constructor parameter has the SAME name as the member variable
    Box(int width) {
        this->width = width;   // this->width = member, width = parameter
        // without "this->", "width = width;" would just assign the parameter to itself!
    }

    // Method chaining: return *this (dereferenced this = the current object)
    Box& setWidth(int w) {
        this->width = w;
        return *this;   // returning the object itself allows chaining calls
    }

    Box& scale(int factor) {
        this->width *= factor;
        return *this;
    }

    void print() {
        cout << "Width: " << this->width << endl;
    }
};

int main() {
    Box b(10);
    b.print();

    // Method chaining works because each method returns *this
    b.setWidth(5).scale(3).print();

    return 0;
}