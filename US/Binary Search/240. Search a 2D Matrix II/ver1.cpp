#include <vector>
using namespace std;

// Algorithm: Search from the right-top

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = 0;
        int y = m-1;
        while(x < n && y >= 0){
            if(matrix[x][y] < target){
                x++;
            }
            else if(matrix[x][y] > target){
                y--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};