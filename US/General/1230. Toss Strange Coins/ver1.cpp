#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        // dp[i][j] means the probability when I tosses i coins and reach the j face up
        vector<vector<double>> dp(n+1, vector<double>(target+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            dp[i][0] = dp[i-1][0] * (1-prob[i-1]);
        }
        for(int i=1; i<=target; i++){
            dp[i][i] = dp[i-1][i-1] * prob[i-1];
        }
        for(int i=1; i<=target; i++){
            for(int j=i+1; j<=n; j++){
                dp[j][i] = dp[j-1][i]*(1-prob[j-1]) + dp[j-1][i-1]*prob[j-1];
            }
        }
        return dp[n][target];
    }
};