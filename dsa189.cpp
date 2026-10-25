// Queue Using Two Stacks

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> in, out;

    void shift() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

public:
    void push(int x) { in.push(x); }

    int pop() {
        shift();
        int v = out.top();
        out.pop();
        return v;
    }

    int peek() {
        shift();
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl;
    q.push(4);
    cout << q.pop() << endl;
    cout << q.peek() << endl;

    return 0;
}