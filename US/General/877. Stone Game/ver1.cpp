#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> cumsum(n, 0);
        cumsum[0] = piles[0];
        for(int i=1; i<n; i++){
            cumsum[i] = cumsum[i-1]+piles[i];
        }
        // dp[i][j] means the max stones can get at piles[i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i] = piles[i];
        }
        for(int i=1; i<n; i++){  // length
            for(int j=0; j<n; j++){  // begin
                int k = j + i;  // end
                if(k >= n){
                    break;
                }
                int choose_begin = cumsum[k]-cumsum[j+1]+piles[j+1]-dp[j+1][k]+piles[j];
                int choose_end = cumsum[k-1]-cumsum[j]+piles[j]-dp[j][k-1]+piles[k];
                dp[j][k] = max(choose_begin, choose_end);
            }
        }
        return dp[0][n-1]*2 > cumsum[n-1];
    }
};