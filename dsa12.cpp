 #include <iostream>
 using namespace std;

 int main() {
    int n ;
    cout<< " enter n"<<endl;
    cin>> n;
    int i =1;
    while (i<=n) {
        // print space 
        int space = n-i;
            while (space) {
                cout <<" ";
                space--;
            }
            // print stars
            int j =1;
            while (j<=i) {   
                cout << "*";
                j++;
            }
            
        cout<< endl;
        i++;
    }
    return 0;
 }