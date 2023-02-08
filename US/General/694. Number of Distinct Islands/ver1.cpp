#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<int>& route, int row, int col, int m, int n, int init_r, int init_c){
        visited[row][col] = true;
        route.push_back((row-init_r)*n + (col-init_c));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0; i<4; i++){
            int r = row + directions[i][0];
            int c = col + directions[i][1];
            if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c]){
                continue;
            }
            dfs(grid, visited, route, r, c, m, n, init_r, init_c);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> routes;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<int> route;
                    dfs(grid, visited, route, i, j, m, n, i, j);
                    // check there is same route
                    bool insert = true;
                    for(auto& r: routes){
                        if(r.size() != route.size()){
                            continue;
                        }
                        bool same = true;
                        for(int i=0; i<r.size(); i++){
                            if(r[i] != route[i]){
                                same = false;
                                break;
                            }
                        }
                        if(same){
                            insert = false;
                            break;
                        }
                    }
                    if(insert){
                        routes.push_back(route);
                    }
                }
            }
        }
        return routes.size();
    }
};