#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[i] means the modulo of i and times by 3
        vector<int> dp(3, -1);
        int n = nums.size();
        for(int i=0; i<n; i++){
            vector<int> new_dp = dp;
            new_dp[nums[i]%3] = max(new_dp[nums[i]%3], nums[i]/3);
            for(int j=0; j<3; j++){
                if(dp[j] == -1){
                    continue;
                }
                int sum = j + dp[j] * 3 + nums[i];
                new_dp[sum%3] = max(new_dp[sum%3], sum / 3);
            }

            dp = new_dp;   
        }
        return dp[0] == -1 ? 0 : dp[0]*3;
    }
};