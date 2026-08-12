#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 5: "<<binary_search(v.begin(), v.end(), 5)<<endl;
    cout<<"finding 6: "<<binary_search(v.begin(), v.end(), 6)<<endl;

    cout<<"lower bound of 6: "<<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;  // means index of lower bound of 6
    cout<<"upper bound of 6: "<<upper_bound(v.begin(), v.end(), 6)-v.begin()<<endl;   // means index of upper bound of 6


    int a = 5;
    int b = 7;

    cout<<"max: "<<max(a, b)<<endl;
    cout<<"min: "<<min(a, b)<<endl;

    swap(a, b);
    cout<<"after swap"<<endl;
    cout<<"a: "<<a<<endl;   
    cout<<"b: "<<b<<endl;


    string str = "pix";
    reverse(str.begin(), str.end());
    cout<<"reversed string: "<<str<<endl;

    vector<int> v1 = {1, 2, 3, 4};                  
    rotate(v1.begin(), v1.begin()+1, v1.end());  // +1 with begin() means we are rotating the vector by 1 position.
    cout<<"after rotate: ";                     // rotate means we are shifting the elements of vector to left or right. Here we are shifting to left by 1 position.
    for(int i: v1){
        cout<<i<<" ";
    }cout<<endl;

    sort(v1.begin(), v1.end());
    cout<<"after sort: ";
    for(int i: v1){
        cout<<i<<" ";
    }cout<<endl;
     
    // intro sort : it is combination of quick sort, heap sort and insertion sort. It is used in STL sort function.

}