#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto comparator = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] > v2[0];
        };
        // priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> q(comparator);
        q.push({0, 0, 0});
        int time = 0;
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while(!q.empty()){
            auto v = q.top();
            q.pop();
            int row = v[1];
            int col = v[2];
            int time = v[0];
            if(row == m-1 && col == n-1){
                return time;
            }
            if(visited[row][col]){
                continue;
            }
            visited[row][col] = true;
            for(int i=0; i<4; i++){
                int r = row + directions[i][0];
                int c = col + directions[i][1];
                if(r < 0 || r >= m || c < 0 || c >= n || visited[r][c]){
                    continue;
                }
                int wait = (grid[r][c] - time) % 2 == 0;
                q.push({max(grid[r][c] + wait, time + 1), r, c});
            }
        }
        return -1;
    }
};