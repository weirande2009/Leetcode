#include <vector>
#include <numeric>
using namespace std;

// Algorithm: dp[i][j] means it possible to form the sum of j without i.
// When it's possible:
// 1) dp[i-1][j] is true, because we don't need to add nums[i].
// 2) dp[i-1][j-nums[i-1]] is true, because if dp[i-1][j-nums[i-1]] is true, then we can also
// add nums[i-1] to it, it can form j.
// which means the recurrence formular if dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
// And initialize dp[0]. dp[0][j] can only be true in which j == nums[0].


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int target = s/2;
        if(s % 2){
            return false;
        }
        // dp[i][j] means it possible to form the sum of j without i
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        dp[0][nums[0]] = true;
        for(int i=1; i<n; i++){
            for(int j=0; j<target+1; j++){
                if(j < nums[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
};