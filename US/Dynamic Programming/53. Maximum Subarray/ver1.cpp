#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        // dp[i][j] means to sum from i to j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int max_sum = -INT_MAX;
        for(int i=0; i<n; i++){
            dp[i][i] = nums[i];
            if(nums[i] > max_sum){
                max_sum = nums[i];
            }
        }
        
        for(int i=2; i<=n; i++){  // Length
            for(int j=0; j<n; j++){  // Start index
                int k = j+i-1;  // end index
                if(k > n-1){
                    break;
                }
                dp[j][k] = dp[j][k-1] + nums[k];
                if(dp[j][k] > max_sum){
                    max_sum = dp[j][k];
                }
            }
        }
        return max_sum;
    }
};