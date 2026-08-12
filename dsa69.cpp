#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<string> q;

    q.push("pix");
    q.push("Prisha");
    q.push("Verma");

    cout <<"First element: "<<q.front() <<endl;
    cout<< "size after pop: "<<q.size()<<endl;
    q.pop();
    cout <<"First element: "<<q.front() <<endl;

    cout<< "size after pop: "<<q.size()<<endl;

}