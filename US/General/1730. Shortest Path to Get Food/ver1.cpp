#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int, int> start;
        bool has_food = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '*'){
                    start = {i, j};
                }
                else if(grid[i][j] == '#'){
                    has_food = true;
                }
            }
        }
        if(!has_food){
            return -1;
        }
        queue<pair<int, int>> q;
        unordered_set<int> route;
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        q.push(start);
        route.insert(start.first*n+start.second);
        int step = 0;
        while(!q.empty()){
            step++;
            queue<pair<int, int>> tmp_q;
            while(!q.empty()){
                auto [row, col] = q.front();
                for(int i=0; i<4; i++){
                    int r = row + directions[i][0];
                    int c = col + directions[i][1];
                    if(r < 0 || r >= m || c < 0 || c >= n || route.find(r*n+c) != route.end() || grid[r][c] == 'X'){
                        continue;
                    }
                    if(grid[r][c] == '#'){
                        return step;
                    }
                    tmp_q.push({r, c});
                    route.insert(r*n+c);
                }
                q.pop();
            }
            q = tmp_q;
        }
        return -1;
    }
};