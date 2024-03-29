#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // dp[i][j] means the max length of the square in (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int count = 0;
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 1){
                count++;
                dp[i][0] = 1;
            }
        }
        for(int i=1; i<n; i++){
            if(matrix[0][i] == 1){
                count++;
                dp[0][i] = 1;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    count += dp[i][j];
                }
            }
        }
        return count;
    }
};