#include <vector>
using namespace std;


// Algorithm: Almost the same as "Unique Paths". The only different is that we need to 
// previously set dp[i][j] where pos(i,j) is obstacle as 0 and when i==0 or j==0, all
// the dp after it should be set to be 0, because there is no way to them.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
         // dp[i][j] means the unique way to pos(i, j)
        vector<vector<int>> dp(m, vector<int>(n, 1));
        bool meet_obstacle = false;
        for(int i=0; i<n; i++){
            if(obstacleGrid[0][i] == 1){
                meet_obstacle = true;
            }
            if(meet_obstacle){
                dp[0][i] = 0;
            }
            else{
                dp[0][i] = 1;
            }
        }
        meet_obstacle = false;
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0] == 1){
                meet_obstacle = true;
            }
            if(meet_obstacle){
                dp[i][0] = 0;
            }
            else{
                dp[i][0] = 1;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    
};