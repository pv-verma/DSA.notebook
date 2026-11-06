// Largest Rectangle in a Histogram (Monotonic Stack)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangle(vector<int>& h) {
    int n = h.size();
    stack<int> st;                  // indices with increasing heights
    int best = 0;

    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : h[i];   // height 0 at the end flushes the stack

        while (!st.empty() && h[st.top()] >= cur) {
            int height = h[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();   // first shorter bar on the left
            best = max(best, height * (i - left - 1));
        }
        st.push(i);
    }
    return best;
}

int main() {
    vector<int> a = {2, 1, 5, 6, 2, 3};
    vector<int> b = {2, 4};

    cout << largestRectangle(a) << endl;
    cout << largestRectangle(b) << endl;
    return 0;
}