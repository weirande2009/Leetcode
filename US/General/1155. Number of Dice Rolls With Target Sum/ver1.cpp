#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][j] means the number of ways to sum to j by using i dice
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for(int i=1; i<=min(k, target); i++){
            dp[0][i] = 1;
        }
        const int MOD = 1000000007;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=min(k*(i+1), target); j++){
                for(int m=1; m<=k; m++){
                    int l = j-m;
                    if(l < i){
                        break;
                    }
                    dp[i][j] = (dp[i][j] + dp[i-1][l]) % MOD;
                }
            }
        }
        return dp[n-1][target];
    }
};