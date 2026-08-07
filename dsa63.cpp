#include <vector>
#include <iostream>
using namespace std;

// Rotated array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      
    // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);
      
      
      for(int i =0;i<n;i++) {
        
        temp[(i+k)%n] = nums[i];
        
      }
      
      
      for(int i=0;i<nums.size();i++) 
      {
        nums[i] = temp[i];
      }
      
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    solution.rotate(nums, k);
    
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}