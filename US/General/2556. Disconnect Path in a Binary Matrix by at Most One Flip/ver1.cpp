#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row == m-1 && col == n-1){
            return true;
        }
        if(row == m || col == n || grid[row][col] == 0){
            return false;
        }
        grid[row][col] = 0;
        return dfs(grid, row+1, col) || dfs(grid, row, col+1);
    }
    
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(!dfs(grid, 0, 0)){
            return true;
        }
        grid[0][0] = 1;
        return !dfs(grid, 0, 0);
    }
};