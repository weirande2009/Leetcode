#include <vector>
using namespace std;

// Algorithm: Use a cache to memorize. cache[i][j] means the max length from (i,j).

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    int Recursion(const vector<vector<int>>& matrix, int x, int y, int n, int m, vector<vector<int>>& cache){
        if(cache[x][y] != 0){
            return cache[x][y];
        }
        for(auto& dir: dirs){
            if(x+dir[0] >= 0 && x+dir[0] <= n-1 && y+dir[1] >= 0 && y+dir[1] <= m-1 && matrix[x+dir[0]][y+dir[1]] > matrix[x][y]){
                cache[x][y] = max(cache[x][y], Recursion(matrix, x+dir[0], y+dir[1], n, m, cache));
            }
        }
        return ++cache[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();        
        vector<vector<int>> cache(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, Recursion(matrix, i, j, n, m, cache));
            }
        }
        return ans;
    }
};