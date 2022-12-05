#include <vector>
using namespace std;


class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& memo, int target){
        if(memo[target] != -1){
            return memo[target];
        }
        int sum = 0;
        // find all ways that sum to target
        for(int num: nums){
            if(target - num >= 0){
                sum += dfs(nums, memo, target-num);
            }
        }
        memo[target] = sum;
        return sum;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // dp[i] means the number of combinations to get to sum of i
        vector<int> memo(target+1, -1);
        memo[0] = 1; // get nothing, so there is one way
        return dfs(nums, memo, target);
    }
};