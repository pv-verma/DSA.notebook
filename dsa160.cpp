// Array of Dynamically Allocated Objects (Pointers to Objects, Not Primitives)

#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int id;

    Employee(string n, int i) : name(n), id(i) {
        cout << "Employee " << name << " (ID " << id << ") created" << endl;
    }

    ~Employee() {
        cout << "Employee " << name << " destroyed" << endl;
    }
};

int main() {
    int n = 3;

    // Array of pointers -- each slot will hold the address of a separate heap object
    Employee** employees = new Employee*[n];

    employees[0] = new Employee("Alice", 101);
    employees[1] = new Employee("Bob", 102);
    employees[2] = new Employee("Charlie", 103);

    cout << "\nEmployee list:\n";
    for (int i = 0; i < n; i++) {
        cout << employees[i]->name << " - ID: " << employees[i]->id << endl;
    }

    cout << "\nCleaning up:\n";
    // Must delete each individual object FIRST...
    for (int i = 0; i < n; i++) {
        delete employees[i];
    }
    // ...THEN delete the array of pointers itself
    delete[] employees;

    return 0;
}