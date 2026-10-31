// Min Stack (Design)

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<int> data;
    stack<int> mins;   // mins.top() is always the minimum of everything in data

public:
    void push(int x) {
        data.push(x);
        if (mins.empty()) mins.push(x);
        else mins.push(min(x, mins.top()));
    }

    void pop() {
        data.pop();
        mins.pop();
    }

    int top() { return data.top(); }

    int getMin() { return mins.top(); }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    return 0;
}