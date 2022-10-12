#include <vector>
#include <cmath>
using namespace std;

// Algorithm: DP. dp[i][j] means the largest side of a square whose right bottom position is (i,j).
// The update function of dp is: dp[i][j]=min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1 for matrix[i][j]
// is '1'. dp[i][j] = 0 for matrix[i][j] is '0'. Then update function means the overlap area(side)
// length of the three rectangle. If any of them is '0'(in matrix), then dp[i][j]=1.

class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int max_side = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j]-'0';
                }
                else if(matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), min(dp[i][j-1], dp[i-1][j-1]))+1;
                }
                if(dp[i][j] > max_side){
                    max_side = dp[i][j];
                }
            }
        }
        return max_side*max_side;
    }
};