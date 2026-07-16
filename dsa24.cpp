#include <iostream>
using namespace std;
    // pow (a,b)

   /* int a, b;
    cin>> a>>b ;
    int ans = 1;

    for (int i=1; i<=b; i++) 
    {
        ans = ans * a;
    }

    cout <<" answer is " << ans << endl;
    */
   int power (int num1 , int num2) {

    int ans = 1;

    for (int i =1; i<=num2; i++) {
        ans = ans * num1;
    }
    return ans;
   } 

   int main() {
    int a , b;
    cin>> a>>b;   

    int answer = power(a,b);  
    cout << " answer is "<<answer <<endl;

    return 0;

   }