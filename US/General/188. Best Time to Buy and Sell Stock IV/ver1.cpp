#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k <= 0 || n <= 0){
            return 0;
        }
        if(2*k > n){
            int profit = 0;
            for(int i=1; i<n; i++){
                if(prices[i] > prices[i-1]){
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
        
        // dp[i][j][l] means the best profit we can make at the end of i-th day, with j remaining transactions to make and l stocks(l can only be 0 or 1)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -100000000)));
        dp[0][0][0] = 0;  // if do nothing at the first day
        dp[0][1][1] = -prices[0];  // if hold the stock at the first day
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                // keep not holding any stock or sell the stock today
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                // you can't hold stock without any transaction
                if(j > 0){
                    // keep holding the stock or buy stock today
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
                }
            }
        }
        int profit = 0;
        for(int i=0; i<=k; i++){
            profit = max(dp[n-1][i][0], profit);
        }
        return profit;
    }
};
