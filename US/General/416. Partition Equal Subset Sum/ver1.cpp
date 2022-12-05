#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return false;
        }
        int s = accumulate(nums.begin(), nums.end(), 0);
        int target = s/2;
        if(s % 2){
            return false;
        }
        // dp[i][j] means it possible to form the sum of j from nums[0] to nums[i]
        vector<vector<bool>> dp(n, vector<bool>(s+1, false));
        dp[0][0] = true;
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