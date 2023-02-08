#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int>& values, vector<vector<int>>& memo, int i, int j){
        if(i+1 == j){
            return 0;
        }
        int n = values.size();
        if(memo[i][j] != 0){
            return memo[i][j];
        }
        int ans = INT_MAX;
        int tmp = values[i] * values[j];
        for(int k=i+1; k<j; k++){
            int product = tmp * values[k];
            ans = min(ans, product+dfs(values, memo, i, k)+dfs(values, memo, k, j));
        }
        memo[i][j] = ans;
        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return dfs(values, memo, 0, n-1);
    }
};