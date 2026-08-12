#include <iostream>
#include <map>
using namespace std;

int main() {

    map<int, string> m;

    m[1] = "pix";
    m[9] = "Verma";
    m[5] = "Prisha";

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    m.insert({0, "hello"});

    cout<<"before erase"<<endl;

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    cout<<"size of map: "<<m.size()<<endl;
    m.erase(1);
    cout<<"after erase"<<endl;
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

}