#include <vector>
#include <limits.h>
using namespace std;


class Solution {
public:
    int dfs(vector<int>& nums, vector<vector<int>>& memo, int left, int right){
        // In each processing, we try to iterate over left to right and take i as the last one to be bursted.
        // because we're sure that if i is the last, the one before it is left-1, and the one after it is right+1.
        if(left > right){
            return 0;
        }
        if(memo[left][right] != -1){
            return memo[left][right];
        }
        int mx = INT_MIN;
        // iterate over from left to right, to mark i as the last balloon to be bursted
        for(int i=left; i<=right; i++){
            // nums[i] is the last balloon to be bursted
            int num = nums[left-1] * nums[i] * nums[right+1];
            // we'll burst left to i-1 and i+1 to right first
            int remaining = dfs(nums, memo, left, i-1) + dfs(nums, memo, i+1, right);
            mx = max(mx, remaining + num);
        }
        memo[left][right] = mx;
        return mx;
    }
    
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        // memo[i][j] means the max coins of subarray from i to j
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(nums, memo, 1, n-2);
    }
};