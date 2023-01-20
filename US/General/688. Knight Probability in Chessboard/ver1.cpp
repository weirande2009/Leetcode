#include <vector>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // dp[i][j][k] means the probability of getting to position(j, k) in i steps
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n+4, vector<double>(n+4, 0)));
        dp[0][row+2][column+2] = 1;
        for(int i=1; i<=k; i++){
            for(int j=2; j<=n+1; j++){
                for(int k=2; k<=n+1; k++){
                    dp[i][j][k] = (dp[i-1][j-2][k+1] + dp[i-1][j-1][k+2] + dp[i-1][j+1][k+2] + dp[i-1][j+2][k+1] + dp[i-1][j-2][k-1] + dp[i-1][j-1][k-2] + dp[i-1][j+1][k-2] + dp[i-1][j+2][k-1]) / 8;
                }
            }
        }
        double total = 0;
        int step = k;
        // compute all prob of remaining inside the board
        for(int j=2; j<=n+1; j++){
            for(int k=2; k<=n+2; k++){
                total += dp[step][j][k];
            }
        }
        return total;
    }
};