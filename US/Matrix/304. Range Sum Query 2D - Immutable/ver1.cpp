#include <vector>
using namespace std;

// Algorithm: Compute a matrix sum_mat where sum_mat[i][j] means the sum from (0,0) to (i,j)
// So when compute sum of a region, time complexity is O(1)

class NumMatrix {
private:
    vector<vector<int>> sum_mat;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sum_mat = vector<vector<int>>(n, vector<int>(m, 0));
        sum_mat[0][0] = matrix[0][0];
        for(int i=1; i<m; i++){
            sum_mat[0][i] = sum_mat[0][i-1] + matrix[0][i];
        }
        for(int i=1; i<n; i++){
            sum_mat[i][0] = sum_mat[i-1][0] + matrix[i][0];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                sum_mat[i][j] = sum_mat[i-1][j] + sum_mat[i][j-1] - sum_mat[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0){
            return sum_mat[row2][col2];
        }
        else if(row1 == 0){
            return sum_mat[row2][col2] - sum_mat[row2][col1-1];
        }
        else if(col1 == 0){
            return sum_mat[row2][col2] - sum_mat[row1-1][col2];
        }
        else{
            return sum_mat[row2][col2] - (sum_mat[row1-1][col2]+sum_mat[row2][col1-1]-sum_mat[row1-1][col1-1]);
        }
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */