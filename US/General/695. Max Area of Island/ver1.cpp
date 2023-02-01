#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, unordered_set<int>& route, int& area, int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        route.insert(r*n+c);
        visited[r][c] = true;
        for(int i=0; i<4; i++){
            int row = r+directions[i][0];
            int col = c+directions[i][1];
            if(row < 0 || row >= m || col < 0 || col >= n || route.find(row*n+col) != route.end()){
                continue;
            }
            if(grid[row][col] == 1){
                area++;
                dfs(grid, visited, route, area, row, col);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = 1;
                    unordered_set<int> route;
                    dfs(grid, visited, route, area, i, j);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};