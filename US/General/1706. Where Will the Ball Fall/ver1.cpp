#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& memo, int row, int col, int m, int n){
        if(row == m){
            return col;
        }
        if(memo[row][col] != -2){
            return memo[row][col];
        }
        int end = -1;
        if(grid[row][col] == 1){
            if(col+1 < n && grid[row][col+1] == 1){
                end = dfs(grid, memo, row+1, col+1, m, n);
            }
        }
        else{
            if(col-1 >= 0 && grid[row][col-1] == -1){
                end = dfs(grid, memo, row+1, col-1, m, n);
            }
        }
        memo[row][col] = end;
        return end;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -2));
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = dfs(grid, memo, 0, i, m, n);
        }
        return ans;
    }
};