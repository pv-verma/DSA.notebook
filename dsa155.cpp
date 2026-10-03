//  Reference-Counted Shared Ownership

#include <iostream>
#include <memory>
using namespace std;

struct Student {
    string name;

    Student(string n) : name(n) {
        cout << "Student " << name << " created" << endl;
    }

    ~Student() {
        cout << "Student " << name << " destroyed" << endl;
    }
};

int main() {
    shared_ptr<Student> ptr1 = make_shared<Student>("Alice");
    cout << "Reference count after ptr1: " << ptr1.use_count() << endl;

    {
        shared_ptr<Student> ptr2 = ptr1;   // shared ownership, NOT a copy of the Student
        cout << "Reference count after ptr2 copy: " << ptr1.use_count() << endl;

        cout << "ptr2 accessing: " << ptr2->name << endl;

    }   // ptr2 goes out of scope here, but Student is NOT destroyed (ptr1 still owns it)

    cout << "Reference count after ptr2 out of scope: " << ptr1.use_count() << endl;
    cout << "ptr1 still accessing: " << ptr1->name << endl;

    cout << "End of main\n";

    return 0;
}   // ptr1 goes out of scope here -> count drops to 0 -> Student finally destroyed