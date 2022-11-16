#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // dp[i][0] means at the end of ith day, the best profit I can make if I don't hold any stock
        // dp[i][1] means at the end of ith day, the best profit I can make if I do hold a stock
        vector<vector<int>> dp(n, vector<int>(2, -100000000));
        // initialize the first day
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1; i<n; i++){
            // keep not holding stock or sell stock
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            // keep holding stock or buy stock
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};