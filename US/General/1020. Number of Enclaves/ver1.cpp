#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n;
    int m;

public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, unordered_set<int>& route, int row, int col){
        if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || grid[row][col] == 0){
            return;
        }
        visited[row][col] = true;
        route.insert(row*m+col);
        for(int i=0; i<4; i++){
            dfs(grid, visited, route, row+directions[i][0], col+directions[i][1]);
        }
        route.erase(row*m+col);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        unordered_set<int> route;
        for(int i=0; i<n; i++){
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(grid, visited, route, i, 0);
            }
            if(!visited[i][m-1] && grid[i][m-1] == 1){
                dfs(grid, visited, route, i, m-1);
            }
        }
        for(int i=0; i<m; i++){
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(grid, visited, route, 0, i);
            }
            if(!visited[n-1][i] && grid[n-1][i] == 1){
                dfs(grid, visited, route, n-1, i);
            }
        }
        int count = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};