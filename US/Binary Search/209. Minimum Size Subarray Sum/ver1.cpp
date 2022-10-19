#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Algorithm: For each i, we compute the sum from 0 to i in sums[i]. Then, for each i, we find
// the j that sums[j]-sums[i] >= target(here sums[j]-sums[i] means the sum from i to j).
// So we can find the first j by binary search target+sums[i] in sums.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] means the length of i+1, start from j.
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<n+1; i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
        if(dp[n] < target){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=1; i<n+1; i++){
            int to_find = target + dp[i-1];
            auto bound = lower_bound(dp.begin(), dp.end(), to_find);
            if(bound != dp.end()){
                ans = min(ans, (static_cast<int>(bound - (dp.begin()+i-1))));
            }
            
        }
        return ans;
    }
};