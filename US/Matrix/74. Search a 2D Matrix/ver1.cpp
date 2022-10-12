#include <vector>
using namespace std;


// Algorithm: Find the possible row of target in the matrix. Then use binary search to 
// find it.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = -1;
        for(int i=0; i<n; i++){
            if(matrix[i][m-1] >= target){
                row = i;
                break;
            }
        }
        if(row == -1){
            return false;
        }
        int left = 0;
        int right = m-1;
        while(left <= right){
            int mid = (left+right) / 2;
            if(matrix[row][mid] < target){
                left = mid+1;
            }
            else if(matrix[row][mid] > target){
                right = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};