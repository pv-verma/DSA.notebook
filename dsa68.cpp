// STL stacks

#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> s;

    s.push(1);   // adding element at the top
    s.push(2);
    s.push(3);

    cout<< "top: "<<s.top()<<endl; // accessing top element
    cout<<"Size of stack s: "<<s.size()<<endl;   // checking size of stack

    cout<<"before pop"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    cout <<"empty or not "<< s.empty()<<endl;;

    cout<<"after pop"<<endl;
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    cout<<"Size of stack s: "<<s.size()<<endl;   // checking size of stack

}