// stl (vectors)

#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int>v;

    vector<int> a(5,1); // 5 elements with value 1

    vector<int> last(a);  // copy of vector a

    cout<< "print last"<<endl;
    for(int i:last){
        cout<<i<<" ";
    }
    cout<<endl;


    cout << "Capacity of vector a: " << a.capacity() << endl;

    v.push_back(1);
    cout << "Capacity of vector v after adding 1 element: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity of vector v after adding 2 elements: " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity of vector v after adding 3 elements: " << v.capacity() << endl;

    cout << "Size of vector v: " << v.size() << endl;

    cout<<"element in 2nd index: "<<v.at(2)<<endl;

    cout<<"front: "<<v.front()<<endl;

    cout<<"back: "<<v.back()<<endl;

    cout<<"before pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }

    cout<<endl;
    v.pop_back();

    cout<<"after pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"before clear size: "<<v.size()<<endl;
    v.clear();

    cout<<"after clear size: "<<v.size()<<endl;


}