#include <vector>
using namespace std;

// Algorithm: dfs, for every grid, compute the min health needed to enter this grid.
// recursion dp from bottom to up.

class Solution {
public:
    int dfs(vector<vector<int>>& dungeon, vector<vector<int>>& memo, int row, int col, int m, int n){
        if(row == m || col == n){
            return 10000;
        }
        if(memo[row][col] != -1){
            return memo[row][col];
        }
        int left = dfs(dungeon, memo, row, col+1, m, n);
        int right = dfs(dungeon, memo, row+1, col, m, n);
        int health = max(min(left, right)-dungeon[row][col], 1);
        memo[row][col] = health;
        return health;
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // memo means the min health needed to enter position(i, j)
        vector<vector<int>> memo(m, vector<int>(n, -1));
        memo[m-1][n-1] = max(1-dungeon[m-1][n-1], 1);
        return dfs(dungeon, memo, 0, 0, m, n);
    }
};