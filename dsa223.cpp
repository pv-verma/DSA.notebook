// Best Time to Buy and Sell Stock with Cooldown (State DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int hold = -1e9;   // best profit while holding a share
    int sold = 0;      // best profit having just sold today
    int rest = 0;      // best profit holding nothing and free to buy

    for (int p : prices) {
        int prevSold = sold;

        sold = hold + p;                  // sell today
        hold = max(hold, rest - p);       // keep holding, or buy from the free state
        rest = max(rest, prevSold);       // stay free, or finish yesterday's cooldown
    }
    return max(sold, rest);
}

int main() {
    vector<int> a = {1, 2, 3, 0, 2};
    vector<int> b = {1};

    cout << maxProfit(a) << endl;
    cout << maxProfit(b) << endl;
    return 0;
}