#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // dp[i] means the largest sum added to i
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int m = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            m = max(m, dp[i]);
        }
        return m;
    }
};