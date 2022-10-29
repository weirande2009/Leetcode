#include <vector>
#include <algorithm>
using namespace std;

// Algorithm: dp[i][j] means the min number of coins before and including coins[i] to get 
// the sum of j. dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1).

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end(), [](int a, int b){
            return a>b;
        });
        // dp[i][j] means using min number of coins before coins[i] to get the sum of amount
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<amount+1; i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
            else{
                dp[0][i] = -1;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<amount+1; j++){
                if(j < coins[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    if(dp[i-1][j] != -1 && dp[i][j-coins[i]] != -1){
                        dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1);
                    }
                    else if(dp[i-1][j] != -1){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(dp[i][j-coins[i]] != -1){
                        dp[i][j] = dp[i][j-coins[i]] + 1;
                    }
                    else{
                        if(j % coins[i] == 0 && j != 0){
                            dp[i][j] = j/coins[i];
                        }
                        else{
                            dp[i][j] = -1;
                        }
                    }
                }
            }
        }
        return dp[n-1][amount];
    }
};