#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& jobDifficulty, vector<vector<int>>& memo, int d, int i){
        int n = jobDifficulty.size();
        if(n-i == d){
            return accumulate(jobDifficulty.begin()+i, jobDifficulty.end(), 0);
        }
        if(d == 1){
            return *max_element(jobDifficulty.begin()+i, jobDifficulty.end());
        }
        if(memo[i][d] != -1){
            return memo[i][d];
        }
        int mx = 0;
        int ans = INT_MAX;
        for(int j=i; j<=n-d; j++){
            mx = max(mx, jobDifficulty[j]);
            ans = min(ans, mx+dfs(jobDifficulty, memo, d-1, j+1));
        }
        return memo[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> memo(n, vector<int>(d+1, -1));
        int ans = dfs(jobDifficulty, memo, d, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};