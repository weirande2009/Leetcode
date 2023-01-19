#include <vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0){
            return 0;
        }
        const int MOD = 1000000007;
        // dp[i][j][k] means the number of ways to get from start to (j,k) in i steps
        vector<vector<vector<int>>> dp(maxMove, vector<vector<int>>(m+2, vector<int>(n+2, 0)));
        dp[0][startRow+1][startColumn+1] = 1;
        for(int i=1; i<maxMove; i++){
            for(int j=1; j<=m; j++){
                for(int k=1; k<=n; k++){
                    dp[i][j][k] = (dp[i][j][k] + (dp[i-1][j-1][k]+dp[i-1][j+1][k]) % MOD) % MOD;
                    dp[i][j][k] = (dp[i][j][k] + (dp[i-1][j][k-1]+dp[i-1][j][k+1]) % MOD) % MOD;
                }
            }
        }
        int count = 0;
        // count the total number on the side in maxMove-1 steps
        for(int i=0; i<maxMove; i++){
            for(int j=1; j<=n; j++){
                // go up
                count = (count + dp[i][1][j]) % MOD;
                // go down
                count = (count + dp[i][m][j]) % MOD;
            }
            for(int j=1; j<=m; j++){
                // go left
                count = (count + dp[i][j][1]) % MOD;
                // go right
                count = (count + dp[i][j][n]) % MOD;
            }
        }
        return count;
    }
};