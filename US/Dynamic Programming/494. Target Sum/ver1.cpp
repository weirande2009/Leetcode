#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

// Algorithm: dp[i][j] means the number of ways that add to j-sum.
// dp[i][j] = dp[i-1][j+nums[i]] + dp[i-1][j-nums[i]] (means - and +, respectively)


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        target = abs(target);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // dp[i][j] means the ways to add to j before and including nums[i]
        vector<vector<int>> dp(n, vector<int>(2*sum+1, 0));
        dp[0][nums[0]+sum] = 1;
        dp[0][sum-nums[0]] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<2*sum+1; j++){
                if(j <= 2*sum-nums[i]){
                    dp[i][j] += dp[i-1][j+nums[i]];
                }
                if(j >= nums[i]){
                    dp[i][j] += dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][target+sum];
    }
};