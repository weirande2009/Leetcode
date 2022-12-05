#include <vector>
using namespace std;



class Solution {
public:
    bool dfs(vector<int>& stones, vector<vector<int>>& memo, int pos, int jump, int n){
        if(pos == n-1){
            return true;
        }
        if(memo[pos][jump] != -1){
            return memo[pos][jump];
        }
        bool flag = false;
        for(int i=pos+1; i<n; i++){
            if(stones[i] - stones[pos] <= jump+1 && stones[i] - stones[pos] >= jump-1){
                flag |= dfs(stones, memo, i, stones[i] - stones[pos], n);
            }
        }
        memo[pos][jump] = flag;
        return flag;
    }
    
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1){
            return false;
        }
        // memo[i][j] means whether it's possible to jump to the end in i-th stone with last jump j
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(stones, memo, 1, 1, stones.size());
    }
};