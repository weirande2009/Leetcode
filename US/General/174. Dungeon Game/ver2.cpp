#include <vector>
using namespace std;

// loop dp

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, 10000));
        memo[m][n-1] = 1;
        memo[m-1][n] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                memo[i][j] = max(min(memo[i][j+1], memo[i+1][j])-dungeon[i][j], 1);
            }
        }
        return memo[0][0];
    }
};