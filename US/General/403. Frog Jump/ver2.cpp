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
        // using binary search to find the first next stone
        int low = pos+1;
        int high = n-1;
        while(low < high){
            int mid = (low+high) / 2;
            if(stones[mid] - stones[pos] > jump-1){
                high = mid-1;
            }
            else if(stones[mid] - stones[pos] < jump-1){
                low = mid+1;
            }
            else{
                low = mid;
                break;
            }
        }
        if(stones[low] - stones[pos] < jump-1){
            low++;
        }
        // from the searched point
        for(int i=low; i<n; i++){
            if(stones[i] - stones[pos] <= jump+1 && stones[i] - stones[pos] >= jump-1){
                flag |= dfs(stones, memo, i, stones[i] - stones[pos], n);
            }
            else{
                break;
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