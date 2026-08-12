#include <iostream>
#include <set>
using namespace std;

int main() {

    set<int> s;

    s.insert(4);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(2);
    s.insert(5);

    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;

    s.erase(s.begin());

    for(auto i: s){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"4 is present or not: "<<s.count(4)<<endl;
    cout<<"-5 is present or not: "<<s.count(-5)<<endl;

    set<int>::iterator it = s.find(3);
    if(it != s.end()){
        cout<<"3 is present"<<endl;
    }else{
        cout<<"3 is not present"<<endl;
    }
    
    for (auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

}