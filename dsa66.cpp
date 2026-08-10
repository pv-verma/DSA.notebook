// STL (deque)

#include <iostream>
#include <deque>
using namespace std;

int main() {

    deque<int> d;

    d.push_back(1);   // adding element at the end
    d.push_front(2);

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    /*d.pop_back();  // removing element from the end
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    d.pop_front();  // removing element from the front
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    */

    cout<< "print 1st index: "<<d.at(1)<<endl; // accessing element at index 1
    cout<< "front: "<<d.front()<<endl; // accessing first element
    cout<< "back: "<<d.back()<<endl;   // accessing last element
    cout<<"empty or not: "<<d.empty()<<endl;   // checking if deque is empty or not

    cout<<"Size of deque d: "<<d.size()<<endl;   // checking size of deque

    cout<<"before erase: "<<d.size()<<endl;   // checking size of deque
    d.erase(d.begin(),d.begin()+1);           //   erasing first element
    cout<<"after erase: "<<d.size()<<endl;    // checking size of deque
    for(int i:d){
        cout<<i<<" ";
    }       
    cout<<endl;

}
