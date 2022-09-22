#include <vector>
#include <unordered_set>
using namespace std;

// Algorithm: Use two unordered_set to record the row and column that has 0
// Then traverse the two set and set corresponding row and column to 0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zero_row;
        unordered_set<int> zero_column;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    zero_row.insert(i);
                    zero_column.insert(j);
                }
            }
        }
        for(auto r: zero_row){
            for(int i=0; i<m; i++){
                matrix[r][i] = 0;
            }
        }
        for(auto c: zero_column){
            for(int i=0; i<n; i++){
                matrix[i][c] = 0;
            }
        }
    }
};