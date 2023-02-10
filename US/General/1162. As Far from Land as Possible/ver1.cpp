#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, -1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int step = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = -1;
        while(!q.empty()){
            step++;
            queue<pair<int, int>> tmp_q;
            while(!q.empty()){
                auto& [row, col] = q.front();
                for(int i=0; i<4; i++){
                    int r = row+directions[i][0];
                    int c = col+directions[i][1];
                    if(r < 0 || r >= n || c < 0 ||c >= n || visited[r][c]){
                        continue;
                    }
                    distance[r][c] = step;
                    visited[r][c] = true;
                    tmp_q.push({r, c});
                }
                q.pop();
            }
            q = tmp_q;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    ans = max(ans, distance[i][j]);
                }
            }
        }
        return ans;
    }
};