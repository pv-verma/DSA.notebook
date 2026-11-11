// Evaluate Reverse Polish Notation (Stack)

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (const string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = st.top(); st.pop();      // right operand comes off first
            int a = st.top(); st.pop();

            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}

int main() {
    vector<string> a = {"2", "1", "+", "3", "*"};
    vector<string> b = {"4", "13", "5", "/", "+"};

    cout << evalRPN(a) << endl;
    cout << evalRPN(b) << endl;
    return 0;
}