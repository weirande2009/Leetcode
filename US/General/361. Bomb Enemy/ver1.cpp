#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // dp[i][j][k] means the number of enemies from i-th direction in grid (j,k)
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(m, 0)));
        // right, from left to right
        for(int i=0; i<n; i++){
            int enemy = 0;
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'E'){
                    enemy++;
                }
                else if(grid[i][j] == '0'){
                    dp[0][i][j] = enemy;
                }
                else{
                    enemy = 0;
                }
            }
        }
        // left, from right to left
        for(int i=0; i<n; i++){
            int enemy = 0;
            for(int j=m-1; j>=0; j--){
                if(grid[i][j] == 'E'){
                    enemy++;
                }
                else if(grid[i][j] == '0'){
                    dp[1][i][j] = enemy;
                }
                else{
                    enemy = 0;
                }
            }
        }
        // down, from up to down
        for(int i=0; i<m; i++){
            int enemy = 0;
            for(int j=0; j<n; j++){
                if(grid[j][i] == 'E'){
                    enemy++;
                }
                else if(grid[j][i] == '0'){
                    dp[2][j][i] = enemy;
                }
                else{
                    enemy = 0;
                }
            }
        }
        // up, from down to up
        for(int i=0; i<m; i++){
            int enemy = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[j][i] == 'E'){
                    enemy++;
                }
                else if(grid[j][i] == '0'){
                    dp[3][j][i] = enemy;
                }
                else{
                    enemy = 0;
                }
            }
        }
        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = 0;
                for(int k=0; k<4; k++){
                    sum += dp[k][i][j];
                }
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};