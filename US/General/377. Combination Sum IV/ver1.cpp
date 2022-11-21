#include <vector>
using namespace std;


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // dp[i] means the number of combinations to get to sum of i
        vector<int> dp(target+1, 0);
        dp[0] = 1; // get nothing, so there is one way
        for(int i=1; i<target+1; i++){
            // we iterate over all nums for sum i, so all possible combinations will be calculated
            for(int num: nums){
                // there is a way to add num from (i-num) to get to i
                if(i - num >= 0){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};