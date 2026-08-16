//Sum of All Elements Using accumulate


#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    int sum = accumulate(arr.begin(), arr.end(), 0);

    cout << "Sum: " << sum << endl;
    return 0;
}