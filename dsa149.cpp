// Pointers with Structures (Arrow Operator)

#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
};

void printStudent(Student* s) {
    // Using -> is shorthand for (*s).name and (*s).age
    cout << "Name: " << s->name << ", Age: " << s->age << endl;
}

int main() {
    // 1. Pointer to a stack-allocated struct
    Student s1 = {"Alice", 20};
    Student* ptr1 = &s1;

    cout << "Before modification: ";
    printStudent(ptr1);

    ptr1->age = 21;   // modifies s1 directly through the pointer
    cout << "After modification: ";
    printStudent(ptr1);

    // 2. Dynamically allocated struct on the heap
    Student* ptr2 = new Student;
    ptr2->name = "Bob";
    ptr2->age = 22;

    cout << "\nDynamically allocated student: ";
    printStudent(ptr2);

    delete ptr2;   // must free heap memory manually

    return 0;
}