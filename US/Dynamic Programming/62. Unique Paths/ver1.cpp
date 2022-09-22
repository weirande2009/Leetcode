#include <vector>
using namespace std;

// Algorithm: O(n^2). dp[i][j] means the unique ways' number to pos(i,j).
// Because the robot can only move right or down, dp[i][j] = dp[i-1][j] + dp[i][j-1].
// So we only need to initialize the dp[0][:] and dp[:][0] as 1 and run the double loop.

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] means the unique way to pos(i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int pos_x = 0;
        int pox_y = 0;
        for(int i=1; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++){
            dp[i][0] = 1;
        }
        dp[0][0] = 1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


