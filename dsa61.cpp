#include <iostream>
#include <vector>
using namespace std;

//check sortedrotated array

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i] < nums[i-1])
                cnt++;
        }
        if(nums[nums.size()-1] > nums[0])
            cnt++;
        
        return cnt<=1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 4, 5, 1, 2};
    
    if (solution.check(nums)) {
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is not sorted and rotated." << endl;
    }
    
    return 0;
}