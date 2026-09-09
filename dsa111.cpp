// search in 2D array 2

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex < row && colIndex>=0 ) {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target){
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
        }
        return 0;
    }
};

int main() {
    Solution obj;
    vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    bool ans = obj.searchMatrix(matrix,target);
    if(ans) {
        cout << "Element found " << endl;
    }
    else{
        cout << "Element not found " << endl;
    }
    return 0;
}