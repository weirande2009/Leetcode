#include <vector>
using namespace std;


// 解题思路
// 从矩阵的右上角开始，若小于该数，就向左，若大于就向右


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0){
            return false;
        }
        int m = matrix[0].size();
        if(m == 0){
            return false;
        }
        int i = 0;
        int j = m-1;
        while(1){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            if(j<0 || i>=n){
                return false;
            }
        }
        return false;
    }
};