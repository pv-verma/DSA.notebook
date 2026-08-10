// STL (lists)

#include <iostream>
#include <list> 
using namespace std;

int main() {
    
    list<int> l;

    list<int> n(5,100); // 5 elements with value 100
    cout<< "print n"<<endl;
    for(int i:n){
        cout<<i<<" ";
    }
    cout<<endl;

    l.push_back(1);   // adding element at the end
    l.push_front(2);  // adding element at the front

    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;

    /*l.pop_back();  // removing element from the end
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;

    l.pop_front();  // removing element from the front
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    */

    cout<< "print 1st index: "<<l.front()<<endl; // accessing first element
    cout<< "back: "<<l.back()<<endl;   // accessing last element
    cout<<"empty or not: "<<l.empty()<<endl;   // checking if list is empty or not

    cout<<"Size of list l: "<<l.size()<<endl;   // checking size of list

    cout<< "before erase: "<<l.size()<<endl;   // checking size of list

    l.erase(l.begin());           //   erasing first element
    cout<< "after erase: "<<l.size()<<endl;    // checking size of list
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
}