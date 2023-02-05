#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // total number of friends
        int total = 0;
        // dp[i][j] means the distance in position(i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // store the number of friends in each row
        vector<int> row_friends(m, 0);
        // store the number of friends in each col
        vector<int> col_friends(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    row_friends[i]++;
                    col_friends[j]++;
                    // initially store the distance of all friends to position(0, 0)
                    dp[0][0] += i + j;
                    total++;
                }
            }
        }
        // store the cumulative number of friends in each row
        vector<int> cum_row_friends(m, 0);
        for(int i=1; i<m; i++){
            cum_row_friends[i] = cum_row_friends[i-1] + row_friends[i-1];
        }
        // store the cumulative number of friends in each col
        vector<int> cum_col_friends(n, 0);
        for(int i=1; i<n; i++){
            cum_col_friends[i] = cum_col_friends[i-1] + col_friends[i-1];
        }
        int ans = dp[0][0];
        // compute the first column
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + cum_row_friends[i] - (total-cum_row_friends[i]);
            ans = min(ans, dp[i][0]);
        }
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i][j-1] + cum_col_friends[j] - (total-cum_col_friends[j]);
                ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};