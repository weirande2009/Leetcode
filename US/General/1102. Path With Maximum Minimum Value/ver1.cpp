#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                low = min(low, grid[i][j]);
                high = max(high, grid[i][j]);
            }
        }
        while(low <= high){
            int mid = (low+high) / 2;
            if(existPath(grid, mid)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low-1;
    }

    bool existPath(vector<vector<int>>& grid, int value){
        int m = grid.size();
        int n = grid[0].size();
        // the element is a vector of {score, row, col}
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if(grid[0][0] < value){
            return false;
        }
        q.push({0, 0});
        while(!q.empty()){
            const auto& [row, col] = q.front();
            if(row == m-1 && col == n-1){
                return true;
            }
            for(int i=0; i<4; i++){
                int r = row + directions[i][0];
                int c = col + directions[i][1];
                if(r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || grid[r][c] < value){
                    continue;
                }
                q.push({r, c});
                visited[r][c] = true;
            }
            q.pop();
        }
        return false;
        
    }
};