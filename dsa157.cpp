// weak_ptr - Breaking Circular References

#include <iostream>
#include <memory>
using namespace std;

struct B;   // forward declaration

struct A {
    shared_ptr<B> bPtr;
    ~A() { cout << "A destroyed" << endl; }
};

struct B {
    weak_ptr<A> aPtr;   // weak_ptr instead of shared_ptr -- doesn't increase ref count
    ~B() { cout << "B destroyed" << endl; }
};

int main() {
    {
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();

        a->bPtr = b;      // A holds a shared_ptr to B (increases B's ref count)
        b->aPtr = a;      // B holds a WEAK_ptr to A (does NOT increase A's ref count)

        cout << "A ref count: " << a.use_count() << endl;   // still 1
        cout << "B ref count: " << b.use_count() << endl;   // 2 (a->bPtr + local b)

        // To actually use a weak_ptr, you must "lock" it into a temporary shared_ptr
        if (shared_ptr<A> locked = b->aPtr.lock()) {
            cout << "Successfully accessed A through weak_ptr" << endl;
        }

    }   // both a and b go out of scope here

    cout << "End of main -- both A and B were properly destroyed above" << endl;

    return 0;
}