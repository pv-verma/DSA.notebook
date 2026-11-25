// Sort a Stack Using Recursion

#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& s, int x) {
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    insertSorted(s, x);          // find the spot deeper in the stack
    s.push(t);                   // restore what we lifted on the way down
}

void sortStack(stack<int>& s) {
    if (s.empty()) return;

    int t = s.top();
    s.pop();
    sortStack(s);                // sort everything below first
    insertSorted(s, t);
}

int main() {
    stack<int> s;
    int vals[] = {30, -5, 18, 14, -3};
    for (int v : vals) s.push(v);

    sortStack(s);

    cout << "Popping from top: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}