#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> p;       //max heap

    priority_queue<int, vector<int>, greater<int>> p1;   //min heap

    p.push(1);
    p.push(3);
    p.push(2);
    p.push(10);

    cout<< "size of priority queue: "<<p.size()<<endl;
    int n = p.size();
    for(int i = 0; i < n; i++){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;

    p1.push(1);
    p1.push(3);
    p1.push(2);
    p1.push(10);

    cout<< "size of priority queue: "<<p1.size()<<endl;
    int n1 = p1.size();
    for(int i = 0; i < n1; i++){
        cout<<p1.top()<<" ";
        p1.pop();
    }
    cout<<endl;


    cout<<"empty or not "<<p.empty()<<endl;
    cout<<"empty or not "<<p1.empty()<<endl;
}